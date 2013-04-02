/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/* AUTOMATICALLY GENERATED BY make_tdf VERSION 2.0 FROM TDF 4.1 */

#ifndef ECODES_INCLUDED
#define ECODES_INCLUDED

#include <construct/installtypes.h>

/* CODES FOR ACCESS */
#define e_access_apply_token			1
#define e_access_cond				2
#define e_add_accesses				3
#define e_constant				4
#define e_long_jump_access			5
#define e_no_other_read				6
#define e_no_other_write			7
#define e_out_par				8
#define e_preserve				9
#define e_register				10
#define e_standard_access			11
#define e_used_as_volatile			12
#define e_visible				13

/* CODES FOR AL_TAG */
#define e_al_tag_apply_token			2
#define e_make_al_tag				1

/* CODES FOR AL_TAGDEF */
#define e_make_al_tagdef			1

/* CODES FOR AL_TAGDEF_PROPS */
#define e_make_al_tagdefs			0

/* CODES FOR ALIGNMENT */
#define e_alignment_apply_token			1
#define e_alignment_cond			2
#define e_alignment				3
#define e_alloca_alignment			4
#define e_callees_alignment			5
#define e_callers_alignment			6
#define e_code_alignment			7
#define e_locals_alignment			8
#define e_obtain_al_tag				9
#define e_parameter_alignment			10
#define e_unite_alignments			11
#define e_var_param_alignment			12

/* CODES FOR BITFIELD_VARIETY */
#define e_bfvar_apply_token			1
#define e_bfvar_cond				2
#define e_bfvar_bits				3

/* CODES FOR BOOL */
#define e_bool_apply_token			1
#define e_bool_cond				2
#define e_false					3
#define e_true					4

/* CODES FOR CALLEES */
#define e_make_callee_list			1
#define e_make_dynamic_callees			2
#define e_same_callees				3

/* CODES FOR CAPSULE */
#define e_make_capsule				0

/* CODES FOR CAPSULE_LINK */
#define e_make_capsule_link			0

/* CODES FOR CASELIM */
#define e_make_caselim				0

/* CODES FOR DG */
#define e_dg_apply_token			1
#define e_make_tag_dg				2
#define e_abortable_part_dg			3
#define e_accept_dg				4
#define e_barrier_dg				5
#define e_branch_dg				6
#define e_call_dg				7
#define e_compilation_dg			8
#define e_destructor_dg				9
#define e_exception_handler_dg			10
#define e_exception_scope_dg			11
#define e_inline_call_dg			12
#define e_inline_result_dg			13
#define e_inlined_dg				14
#define e_jump_dg				15
#define e_label_dg				16
#define e_lexical_block_dg			17
#define e_list_dg				18
#define e_long_jump_dg				19
#define e_name_decl_dg				20
#define e_params_dg				21
#define e_raise_dg				22
#define e_requeue_dg				23
#define e_rts_call_dg				24
#define e_select_dg				25
#define e_select_alternative_dg			26
#define e_select_guard_dg			27
#define e_singlestep_dg				28
#define e_source_language_dg			29
#define e_sourcepos_dg				30
#define e_statement_part_dg			31
#define e_test_dg				32
#define e_triggering_alternative_dg		33
#define e_with_dg				34

/* CODES FOR DG_ACCESSIBILITY */
#define e_dg_local_accessibility		1
#define e_dg_private_accessibility		2
#define e_dg_protected_accessibility		3
#define e_dg_public_accessibility		4

/* CODES FOR DG_APPEND */
#define e_dg_name_append			1

/* CODES FOR DG_BOUND */
#define e_dg_dynamic_bound			1
#define e_dg_static_bound			2
#define e_dg_unknown_bound			3

/* CODES FOR DG_CLASS_BASE */
#define e_make_dg_class_base			1

/* CODES FOR DG_CLASSMEM */
#define e_dg_tag_classmem			1
#define e_dg_field_classmem			2
#define e_dg_function_classmem			3
#define e_dg_indirect_classmem			4
#define e_dg_name_classmem			5

/* CODES FOR DG_COMP_PROPS */
#define e_make_dg_compunit			0

/* CODES FOR DG_COMPILATION */
#define e_dg_tag_compilation			1
#define e_make_dg_compilation			2

/* CODES FOR DG_CONSTRAINT */
#define e_dg_type_constraint			1
#define e_dg_value_constraint			2

/* CODES FOR DG_DEFAULT */
#define e_make_dg_default			1

/* CODES FOR DG_DIM */
#define e_dg_dim_apply_token			1
#define e_dg_tag_dim				2
#define e_dg_bounds_dim				3
#define e_dg_count_dim				4
#define e_dg_type_dim				5
#define e_dg_unspecified_dim			6

/* CODES FOR DG_DISCRIM */
#define e_make_dg_discrim			1

/* CODES FOR DG_ENUM */
#define e_dg_tag_enum				1
#define e_make_dg_enum				2
#define e_dg_char_enum				3

/* CODES FOR DG_FILENAME */
#define e_dg_filename_apply_token		1
#define e_make_dg_filename			2

/* CODES FOR DG_IDNAME */
#define e_dg_idname_apply_token			1
#define e_dg_anonymous_idname			2
#define e_dg_artificial_idname			3
#define e_dg_external_idname			4
#define e_dg_instance_idname			5
#define e_dg_sourcestring_idname		6

/* CODES FOR DG_MACRO */
#define e_dg_function_macro			1
#define e_dg_include_macro			2
#define e_dg_object_macro			3
#define e_dg_undef_macro			4

/* CODES FOR DG_NAME */
#define e_dg_name_apply_token			1
#define e_dg_tag_name				2
#define e_dg_constant_name			3
#define e_dg_entry_family_name			4
#define e_dg_entry_name				5
#define e_dg_inlined_name			6
#define e_dg_is_spec_name			7
#define e_dg_module_name			8
#define e_dg_namespace_name			9
#define e_dg_object_name			10
#define e_dg_proc_name				11
#define e_dg_program_name			12
#define e_dg_rep_clause_name			13
#define e_dg_spec_ref_name			14
#define e_dg_subunit_name			15
#define e_dg_type_name				16
#define e_dg_visibility_name			17

/* CODES FOR DG_NAMELIST */
#define e_dg_tag_namelist			1
#define e_make_dg_namelist			2

/* CODES FOR DG_PARAM */
#define e_dg_object_param			1
#define e_dg_type_param				2

/* CODES FOR DG_PARAM_MODE */
#define e_dg_in_mode				1
#define e_dg_inout_mode				2
#define e_dg_out_mode				3

/* CODES FOR DG_QUALIFIER */
#define e_dg_aliased_qualifier			1
#define e_dg_class_wide_qualifier		2
#define e_dg_const_qualifier			3
#define e_dg_limited_qualifier			4
#define e_dg_volatile_qualifier			5

/* CODES FOR DG_SOURCEPOS */
#define e_dg_file_sourcepos			1
#define e_dg_global_sourcepos			2
#define e_dg_mark_sourcepos			3
#define e_dg_null_sourcepos			4
#define e_dg_span_sourcepos			5

/* CODES FOR DG_TAG */
#define e_make_dg_tag				1

/* CODES FOR DG_TYPE */
#define e_dg_type_apply_token			1
#define e_dg_tag_type				2
#define e_dg_address_type			3
#define e_dg_array_type				4
#define e_dg_bitfield_type			5
#define e_dg_boolean_type			6
#define e_dg_char_type				7
#define e_dg_class_type				8
#define e_dg_complex_float_type			9
#define e_dg_enum_type				10
#define e_dg_file_type				11
#define e_dg_fixed_point_type			12
#define e_dg_float_type				13
#define e_dg_floating_digits_type		14
#define e_dg_inlined_type			15
#define e_dg_integer_type			16
#define e_dg_is_spec_type			17
#define e_dg_modular_type			18
#define e_dg_named_type				19
#define e_dg_packed_type			20
#define e_dg_pointer_type			21
#define e_dg_proc_type				22
#define e_dg_ptr_memdata_type			23
#define e_dg_ptr_memfn_type			24
#define e_dg_qualified_type			25
#define e_dg_reference_type			26
#define e_dg_set_type				27
#define e_dg_spec_ref_type			28
#define e_dg_string_type			29
#define e_dg_struct_type			30
#define e_dg_subrange_type			31
#define e_dg_synchronous_type			32
#define e_dg_task_type				33
#define e_dg_unknown_type			34
#define e_dg_void_type				35

/* CODES FOR DG_VARIANT */
#define e_make_dg_variant			1

/* CODES FOR DG_VARPART */
#define e_dg_discrim_varpart			1
#define e_dg_sibl_discrim_varpart		2
#define e_dg_undiscrim_varpart			3

/* CODES FOR DG_VIRTUALITY */
#define e_dg_abstract_virtuality		1
#define e_dg_virtual_virtuality			2

/* CODES FOR DIAG_DESCRIPTOR */
#define e_diag_desc_id				1
#define e_diag_desc_struct			2
#define e_diag_desc_typedef			3

/* CODES FOR DIAG_FIELD */
#define e_make_diag_field			0

/* CODES FOR DIAG_TAG */
#define e_make_diag_tag				1

/* CODES FOR DIAG_TAGDEF */
#define e_make_diag_tagdef			1

/* CODES FOR DIAG_TQ */
#define e_add_diag_const			1
#define e_add_diag_volatile			2
#define e_diag_tq_null				3

/* CODES FOR DIAG_TYPE */
#define e_diag_type_apply_token			1
#define e_diag_array				2
#define e_diag_bitfield				3
#define e_diag_enum				4
#define e_diag_floating_variety			5
#define e_diag_loc				6
#define e_diag_proc				7
#define e_diag_ptr				8
#define e_diag_struct				9
#define e_diag_type_null			10
#define e_diag_union				11
#define e_diag_variety				12
#define e_use_diag_tag				13

/* CODES FOR DIAG_TYPE_UNIT */
#define e_build_diagtype_unit			0

/* CODES FOR DIAG_UNIT */
#define e_build_diag_unit			0

/* CODES FOR ENUM_VALUES */
#define e_make_enum_values			0

/* CODES FOR ERROR_CODE */
#define e_nil_access				1
#define e_overflow				2
#define e_stack_overflow			3

/* CODES FOR ERROR_TREATMENT */
#define e_errt_apply_token			1
#define e_errt_cond				2
#define e_continue				3
#define e_error_jump				4
#define e_trap					5
#define e_wrap					6
#define e_impossible				7

/* CODES FOR EXP */
#define e_exp_apply_token			1
#define e_exp_cond				2
#define e_abs					3
#define e_add_to_ptr				4
#define e_and					5
#define e_apply_proc				6
#define e_apply_general_proc			7
#define e_assign				8
#define e_assign_with_mode			9
#define e_bitfield_assign			10
#define e_bitfield_assign_with_mode		11
#define e_bitfield_contents			12
#define e_bitfield_contents_with_mode		13
#define e_case					14
#define e_change_bitfield_to_int		15
#define e_change_floating_variety		16
#define e_change_variety			17
#define e_change_int_to_bitfield		18
#define e_complex_conjugate			19
#define e_component				20
#define e_concat_nof				21
#define e_conditional				22
#define e_contents				23
#define e_contents_with_mode			24
#define e_current_env				25
#define e_div0					26
#define e_div1					27
#define e_div2					28
#define e_env_offset				29
#define e_env_size				30
#define e_fail_installer			31
#define e_float_int				32
#define e_floating_abs				33
#define e_floating_div				34
#define e_floating_minus			35
#define e_floating_maximum			36
#define e_floating_minimum			37
#define e_floating_mult				38
#define e_floating_negate			39
#define e_floating_plus				40
#define e_floating_power			41
#define e_floating_test				42
#define e_goto					43
#define e_goto_local_lv				44
#define e_identify				45
#define e_ignorable				46
#define e_imaginary_part			47
#define e_initial_value				48
#define e_integer_test				49
#define e_labelled				50
#define e_last_local				51
#define e_local_alloc				52
#define e_local_alloc_check			53
#define e_local_free				54
#define e_local_free_all			55
#define e_long_jump				56
#define e_make_complex				57
#define e_make_compound				58
#define e_make_floating				59
#define e_make_general_proc			60
#define e_make_int				61
#define e_make_local_lv				62
#define e_make_nof				63
#define e_make_nof_int				64
#define e_make_null_local_lv			65
#define e_make_null_proc			66
#define e_make_null_ptr				67
#define e_make_proc				68
#define e_make_stack_limit			116
#define e_make_top				69
#define e_make_value				70
#define e_maximum				71
#define e_minimum				72
#define e_minus					73
#define e_move_some				74
#define e_mult					75
#define e_n_copies				76
#define e_negate				77
#define e_not					78
#define e_obtain_tag				79
#define e_offset_add				80
#define e_offset_div				81
#define e_offset_div_by_int			82
#define e_offset_max				83
#define e_offset_mult				84
#define e_offset_negate				85
#define e_offset_pad				86
#define e_offset_subtract			87
#define e_offset_test				88
#define e_offset_zero				89
#define e_or					90
#define e_plus					91
#define e_pointer_test				92
#define e_power					93
#define e_proc_test				94
#define e_profile				95
#define e_real_part				96
#define e_rem0					97
#define e_rem1					98
#define e_rem2					99
#define e_repeat				100
#define e_return				101
#define e_return_to_label			102
#define e_round_with_mode			103
#define e_rotate_left				104
#define e_rotate_right				105
#define e_sequence				106
#define e_set_stack_limit			107
#define e_shape_offset				108
#define e_shift_left				109
#define e_shift_right				110
#define e_subtract_ptrs				111
#define e_tail_call				112
#define e_untidy_return				113
#define e_variable				114
#define e_xor					115

/* CODES FOR EXTERN_LINK */
#define e_make_extern_link			0

/* CODES FOR EXTERNAL */
#define e_string_extern				1
#define e_unique_extern				2
#define e_chain_extern				3

/* CODES FOR FILENAME */
#define e_filename_apply_token			1
#define e_make_filename				2

/* CODES FOR FLOATING_VARIETY */
#define e_flvar_apply_token			1
#define e_flvar_cond				2
#define e_flvar_parms				3
#define e_complex_parms				4
#define e_float_of_complex			5
#define e_complex_of_float			6

/* CODES FOR GROUP */
#define e_make_group				0

/* CODES FOR LABEL */
#define e_label_apply_token			2
#define e_make_label				1

/* CODES FOR LINK */
#define e_make_link				0

/* CODES FOR LINKEXTERN */
#define e_make_linkextern			0

/* CODES FOR LINKINFO */
#define e_static_name_def			1
#define e_make_comment				2
#define e_make_weak_defn			3
#define e_make_weak_symbol			4

/* CODES FOR LINKINFO_PROPS */
#define e_make_linkinfos			0

/* CODES FOR LINKS */
#define e_make_links				0

/* CODES FOR NAT */
#define e_nat_apply_token			1
#define e_nat_cond				2
#define e_computed_nat				3
#define e_error_val				4
#define e_make_nat				5

/* CODES FOR NTEST */
#define e_ntest_apply_token			1
#define e_ntest_cond				2
#define e_equal					3
#define e_greater_than				4
#define e_greater_than_or_equal			5
#define e_less_than				6
#define e_less_than_or_equal			7
#define e_not_equal				8
#define e_not_greater_than			9
#define e_not_greater_than_or_equal		10
#define e_not_less_than				11
#define e_not_less_than_or_equal		12
#define e_less_than_or_greater_than		13
#define e_not_less_than_and_not_greater_than	14
#define e_comparable				15
#define e_not_comparable			16

/* CODES FOR OTAGEXP */
#define e_make_otagexp				0

/* CODES FOR PROCPROPS */
#define e_procprops_apply_token			1
#define e_procprops_cond			2
#define e_add_procprops				3
#define e_check_stack				4
#define e_inline				5
#define e_no_long_jump_dest			6
#define e_untidy				7
#define e_var_callees				8
#define e_var_callers				9

/* CODES FOR ROUNDING_MODE */
#define e_rounding_mode_apply_token		1
#define e_rounding_mode_cond			2
#define e_round_as_state			3
#define e_to_nearest				4
#define e_toward_larger				5
#define e_toward_smaller			6
#define e_toward_zero				7

/* CODES FOR SHAPE */
#define e_shape_apply_token			1
#define e_shape_cond				2
#define e_bitfield				3
#define e_bottom				4
#define e_compound				5
#define e_floating				6
#define e_integer				7
#define e_nof					8
#define e_offset				9
#define e_pointer				10
#define e_proc					11
#define e_top					12

/* CODES FOR SIGNED_NAT */
#define e_signed_nat_apply_token		1
#define e_signed_nat_cond			2
#define e_computed_signed_nat			3
#define e_make_signed_nat			4
#define e_snat_from_nat				5

/* CODES FOR SORTNAME */
#define e_access				1
#define e_al_tag				2
#define e_alignment_sort			3
#define e_bitfield_variety			4
#define e_bool					5
#define e_error_treatment			6
#define e_exp					7
#define e_floating_variety			8
#define e_foreign_sort				9
#define e_label					10
#define e_nat					11
#define e_ntest					12
#define e_procprops				13
#define e_rounding_mode				14
#define e_shape					15
#define e_signed_nat				16
#define e_string				17
#define e_tag					18
#define e_transfer_mode				19
#define e_token					20
#define e_variety				21

/* CODES FOR SOURCEMARK */
#define e_make_sourcemark			1

/* CODES FOR STRING */
#define e_string_apply_token			1
#define e_string_cond				2
#define e_concat_string				3
#define e_make_string				4

/* CODES FOR TAG */
#define e_tag_apply_token			2
#define e_make_tag				1

/* CODES FOR TAGACC */
#define e_make_tagacc				0

/* CODES FOR TAGDEC */
#define e_make_id_tagdec			1
#define e_make_var_tagdec			2
#define e_common_tagdec				3

/* CODES FOR TAGDEC_PROPS */
#define e_make_tagdecs				0

/* CODES FOR TAGDEF */
#define e_make_id_tagdef			1
#define e_make_var_tagdef			2
#define e_common_tagdef				3

/* CODES FOR TAGDEF_PROPS */
#define e_make_tagdefs				0

/* CODES FOR TAGSHACC */
#define e_make_tagshacc				0

/* CODES FOR TOKDEC */
#define e_make_tokdec				1

/* CODES FOR TOKDEC_PROPS */
#define e_make_tokdecs				0

/* CODES FOR TOKDEF */
#define e_make_tokdef				1

/* CODES FOR TOKDEF_PROPS */
#define e_make_tokdefs				0

/* CODES FOR TOKEN */
#define e_token_apply_token			1
#define e_make_tok				2
#define e_use_tokdef				3

/* CODES FOR TOKEN_DEFN */
#define e_token_definition			1

/* CODES FOR TOKFORMALS */
#define e_make_tokformals			0

/* CODES FOR TRANSFER_MODE */
#define e_transfer_mode_apply_token		1
#define e_transfer_mode_cond			2
#define e_add_modes				3
#define e_overlap				4
#define e_standard_transfer_mode		5
#define e_trap_on_nil				6
#define e_volatile				7
#define e_complete				8

/* CODES FOR UNIQUE */
#define e_make_unique				0

/* CODES FOR UNIT */
#define e_make_unit				0

/* CODES FOR VARIETY */
#define e_var_apply_token			1
#define e_var_cond				2
#define e_var_limits				3
#define e_var_width				4

/* CODES FOR VERSION */
#define e_make_version				1
#define e_user_info				2

/* CODES FOR VERSION_PROPS */
#define e_make_versions				0


#endif
