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

fn main() {
    // ex_hello_world();
    // ex_formatted_print();
    // debug_1_2_1::ex_debug_print();
    // debug_1_2_1::ex_debug_struct();
    // debug_1_2_1::ex_custom_display();
    // debug_1_2_1::ex_print_point();
    // debug_1_2_1::ex_print_list();

    // ex_print_list();

    // learn_types::check_array_types();

    // primitives:
    // primitives::look_first_at_types();
    // primitives::look_literals();
    // primitives::look_tuples();
    // primitives::look_array_slices();

    // custom types:
    // custom_types::look_custom_types();
    // ex_use_custom_type();
    // ex_use_custom_rectangle();
    // custom_types::look_enum_inspect();
    // custom_types::look_enum_op();
    // custom_types::look_enum_scopes();

    // linked_list::look_linked_list_basics();
    // smart_pointers::look_raw_pointers();
    // smart_pointers::look_box();
    // smart_pointers::look_box_move();
    // rc_ptr::look_rc_ptr();
    rc_ptr::look_rc_cell_ptr();

}

// rust compiles in crates like C#
fn ex_hello_world() {
    println!("Hello world!");
}

fn ex_formatted_print() {

    // named argument
    println!("{subject}", subject="hello");

    // number formats
    println!("{:b}", 69420);
    println!("{:o}", 69420);
    println!("{:x}", 69420);
    println!("{:X}", 69420);

    // alignment and padding
    println!("{number:>5}", number=1);
    println!("{number:0<5}", number=1); // 직관적이지는 않다. 5자리의 뒤 쪽에 0을 채운다.

    // capture directly from env
    let number = 3;
    let width = 5;

    println!("{number:>width$}"); // $ sign required
}

fn ex_print_list() {
    let vec = vec![9, 11, 13, 17, 19];
    let lst = debug_1_2_1::List(vec);

    println!("{}", lst);
}
    
fn ex_use_custom_type() {
    let point = custom_types::Point::from(3.3, 4.4);
    println!("{}", point);
}

fn ex_use_custom_rectangle() {
    let rect = custom_types::Rectangle::from(1.0, 1.0, 30.0, 30.0);
    let area = rect.area();

    println!("area:{}", area);

    let pos = custom_types::Point::from(3.0, 5.0);
    let rect = custom_types::Rectangle::sqaure(pos, 10_f32);
    let area = rect.area();

    println!("area:{}", area);
    // debug_assert가 debug 버전에서만 활성화됨
    debug_assert!(area == 10_f32*10_f32);
}