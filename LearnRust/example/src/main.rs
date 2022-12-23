// mod 선언은 c++의 include와 유사하다. crate 전체에 걸친다는 점이 다르다.
// #!는 crate 수준의 속성 주석(annotation)이다. 
#![allow(dead_code)]

mod debug_1_2_1;
mod learn_types;
mod primitives;
mod custom_types;
mod linked_list;
mod smart_pointers;
mod rc_ptr;
mod variable_bindings;
mod types;
mod conversion;
mod expressions;
mod flow_of_control;
mod functions;
mod generics;
mod scoping;
mod ownership;
mod lifetime;
mod traits;
mod macros;
mod error_handling;
mod library;

fn main() {
    println!("use following command:");
    println!("cargo test -- --nocapture");
}


#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_debug() {
        debug_1_2_1::ex_debug_print();
        debug_1_2_1::ex_debug_struct();
        debug_1_2_1::ex_custom_display();
        debug_1_2_1::ex_print_point();
        debug_1_2_1::ex_print_list();
    }

    #[test]
    fn test_learn_types() {
        learn_types::check_array_types();
    }

    #[test]
    fn test_primitives() {
        primitives::look_first_at_types();
        primitives::look_literals();
        primitives::look_tuples();
        primitives::look_array_slices();
    }

    #[test]
    fn test_custom_types() {
        custom_types::look_custom_types();
        custom_types::look_enum_inspect();
        custom_types::look_enum_op();
        custom_types::look_enum_scopes();
    }

    #[test]
    fn test_smart_pointers() {
        linked_list::look_linked_list_basics();
        smart_pointers::look_raw_pointers();
        smart_pointers::look_box();
        smart_pointers::look_box_move();
        rc_ptr::look_rc_ptr();
        rc_ptr::look_rc_cell_ptr();
    }

    #[test]
    // cargo test로 실행하면 prinlnt! 출력이 사라진다. 
    // cargo test -- --nocapture로 실행해야 한다
    fn test_variable_bindings() {
        variable_bindings::look_variable_bindings();
        variable_bindings::look_mutable_bindings();
        variable_bindings::look_binding_scope();
        variable_bindings::look_variable_shadowing();
        variable_bindings::look_binding_freeze();
    }

    #[test]
    fn test_types() {
       types::look_at_conversions(); 
       types::look_type_literals();
       types::look_type_inference();
       types::look_type_aliases();
    }

    #[test]
    fn test_conversions() {
        conversion::look_from_num();
        conversion::look_into_num();
        conversion::look_try_from();
        conversion::look_parse_from_string();
    }

    #[test]
    fn test_expressions() {
        expressions::look_basic_expressions();
    }

    #[test]
    fn test_flow_of_control() {
        flow_of_control::look_if_else();
        flow_of_control::look_loop();
        flow_of_control::look_range_for();
        flow_of_control::look_iter_for();
        flow_of_control::look_match_tuple_destructuring();
        flow_of_control::look_match_array_destructuring();
        flow_of_control::look_match_enum();
        flow_of_control::look_match_ref_ptr();
        flow_of_control::look_match_struct();
        flow_of_control::look_match_guard();
        flow_of_control::look_match_binding();
        flow_of_control::look_if_let();
        flow_of_control::look_if_let_enum();
        flow_of_control::look_while_let();
    }

    #[test]
    fn test_functions() {
        functions::look_function_basics();
        functions::look_method();
        functions::look_capture_move();
        functions::look_closure_args();
        functions::look_function_args();
        functions::look_closure_returns();
        functions::look_std_any();
        functions::look_higher_order_function();
    }

    #[test]
    fn test_generics() {
        generics::look_basic();
        generics::look_generic_functions();
        generics::look_impl();
        generics::look_impl_2();
        generics::look_bounds();
        generics::look_multi_bounds();
        generics::look_bound_where();
        generics::look_associated_types_with_trait();
        generics::look_phantom_data();
    }

    #[test]
    fn test_scoping() {
        scoping::look_raii();
        scoping::look_ownership_move();
        scoping::look_mutability();
        scoping::look_partial_moves();
        scoping::look_borrowing();
        scoping::look_mutable_borrow();
    }

    #[test]
    fn test_ownership() {
        ownership::look_string();
        ownership::look_move_or_copy();
        ownership::look_references_1();
    }

    #[test]
    fn test_lifetime() {
        lifetime::look_basic_lifetime();
        lifetime::look_lifetime_annotation();
        lifetime::look_lifetime_annotations_for_functions();
        lifetime::look_lifetime_annotions_for_methods();
        lifetime::look_lifetime_annotations_for_types();
        lifetime::look_lifetime_annotations_for_traits();
        lifetime::look_lifetime_bounds();
        lifetime::look_lifetime_coercion();
        lifetime::look_lifetime_annotation_necessity();
    }

    #[test]
    fn test_traits() {
        traits::look_trait_basics();
        traits::look_iterator();
        traits::look_impl_trait_return();
        traits::look_closure_return();
        traits::look_map_return();
        traits::look_clone();
        traits::look_as_to_cast();
    }

    #[test]
    fn test_macros() {
        macros::look_first_macro();
        macros::look_more_macros();
        macros::print_result!(3 + 5);
        macros::look_overloading();
        macros::look_macro_repeat();
        macros::look_variadic_macro();
    }

    #[test]
    fn test_error_handling() {
        // error_handling::look_panic();
        error_handling::look_panic_cfg();
        error_handling::look_some_for_panic();
        error_handling::look_more_options();
        error_handling::look_option_chaining_with_map();

        let result = error_handling::look_parse_with_result();
        println!("parse: {:?}", result);

        error_handling::look_combinator_map_for_result();
        error_handling::custom_result::look();
    }

    #[test]
    fn test_library() {
        library::look_box();
        library::look_vector();
        library::look_string();
        library::look_result();
        library::look_hashmap();
        library::look_hashset();
        library::look_rc();
        library::look_arc();
    }
}