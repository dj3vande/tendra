/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/*
 * This file assumes that the parameters to the functions defined here are
 * 64-bit integers:
 *
 *   Tokdef  INT64 = [] SHAPE  integer (var_width(true,  64));
 *   Tokdef UINT64 = [] SHAPE  integer (var_width(false, 64));
 *
 * If it required that structures be passed, changing these tokens definitions
 * to:
 *   Tokdef  INT64 = [] SHAPE   STRUCT_64;
 *   Tokdef UINT64 = [] SHAPE  USTRUCT_64;
 *
 * (and putting them in an appropriate place further down the file) should
 * produce the required behaviour.
 */

/*
 * This file contains PL_TDF token definitions which are declared in the
 * PL_TDF file abstract.tph.
 */

/*
 * Define the generic 32-bit signed and unsigned types
 */
Tokdef  ~INT32 = [] VARIETY  var_width (true, 32);
Tokdef   INT32 = [] SHAPE    integer(~INT32);
Tokdef ~UINT32 = [] VARIETY  var_width (false, 32);
Tokdef  UINT32 = [] SHAPE    integer(~UINT32);

/*
 * Define the new types for 64-bit integers and macros
 * for extracting the high- and low-32 bits.
 */
Tokdef  INT64 = [] SHAPE integer(var_width(true,  64));
Tokdef UINT64 = [] SHAPE integer(var_width(false, 64));

/*
 * These are defined in the target-dependent tokens library
 */
Tokdec .~rep_fv       : [NAT] FLOATING_VARIETY;
Tokdec .~rep_fv_width : [NAT] NAT;

/*
 * Define the widest floating variety - not possible in C
 */
Tokdec rep_fv : [NAT] FLOATING_VARIETY;
Tokdef rep_fv = [n:NAT] FLOATING_VARIETY
	FLOATING_VARIETY ? ( ? { ? ((+ .~rep_fv_width [
		computed_nat(1(Int) + (+ n(Int)))] (Int)) == 0(Int));
			1(Int)
		|
			0(Int)
		},
			.~rep_fv [n],
			rep_fv [computed_nat(1(Int) + (+ n(Int)))]
	);

Tokdef ~BigFloat = [] FLOATING_VARIETY rep_fv [1];
Tokdef  BigFloat = [] SHAPE floating(~BigFloat);

/*
 * Macros for extracting the high- and low-32 bits
 *
 * (These necessarily differ from the C equivalents)
 */

/* This is a boolean preserved by the .c files */
Tokdec BIGEND_INT64 : [] EXP;

Tokdef s1 = [] SHAPE  SHAPE ? ( BIGEND_INT64,  INT32, UINT32 );
Tokdef s2 = [] SHAPE  SHAPE ? ( BIGEND_INT64, UINT32,  INT32 );

Struct STRUCT_64  (x1 : s1, x2 : s2);
Struct STRUCT_U64 (x3 : UINT32, x4 : UINT32);

Tokdef hi_32  = [a:EXP] EXP  EXP ? ( BIGEND_INT64, x1[a], x2[a]);
Tokdef lo_32  = [a:EXP] EXP  EXP ? ( BIGEND_INT64, x2[a], x1[a]);
Tokdef hi_u32 = [a:EXP] EXP  EXP ? ( BIGEND_INT64, x3[a], x4[a]);
Tokdef lo_u32 = [a:EXP] EXP  EXP ? ( BIGEND_INT64, x4[a], x3[a]);

Tokdef .hi_32  = [] EXP  EXP ? ( BIGEND_INT64, .x1, .x2);
Tokdef .lo_32  = [] EXP  EXP ? ( BIGEND_INT64, .x2, .x1);
Tokdef .hi_u32 = [] EXP  EXP ? ( BIGEND_INT64, .x3, .x4);
Tokdef .lo_u32 = [] EXP  EXP ? ( BIGEND_INT64, .x4, .x3);

/*
Struct STRUCT_64  (hi_32  : INT32, lo_32  : UINT32 );
Struct STRUCT_U64 (hi_u32 : UINT32, lo_u32 : UINT32 );
*/

Struct Union64  ( PARAM :  INT64);
Struct UnionU64 (UPARAM : UINT64);

Tokdef TDF_INT64 = [] SHAPE
	compound (shape_offset(INT64) .max. shape_offset(STRUCT_64));

/*
 * 64-bit constants used in the implementation
 */

Tokdef const_0  = [] EXP
	Cons [shape_offset(TDF_INT64)] (.lo_32: 0(~UINT32), .hi_32: 0(~INT32));

Tokdef const_u0 = [] EXP
	Cons [shape_offset(TDF_INT64)] (.lo_u32: 0(~UINT32), .hi_u32: 0(~INT32));

Tokdef const_1  = [] EXP
	Cons [shape_offset(TDF_INT64)] (.lo_32: 1(~UINT32), .hi_32: 0(~INT32));

Tokdef const_u1 = [] EXP
	Cons [shape_offset(TDF_INT64)] (.lo_u32: 1(~UINT32), .hi_u32: 0(~INT32));

Keep (
	~INT32, ~UINT32, INT32, UINT32, INT64, UINT64, TDF_INT64,
	~BigFloat, BigFloat, PARAM, .PARAM, UPARAM, .UPARAM,
	hi_32, lo_32, hi_u32, lo_u32, .hi_32, .lo_32, .hi_u32, .lo_u32,
	const_0, const_u0, const_1, const_u1
)

