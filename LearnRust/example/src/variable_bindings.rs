// mod variable_bindings 

pub fn look_variable_bindings() {
  let an_integer = 1_u32;
  let a_boolean = true;
  let unit = ();

  // copy `an_integer` into `copied_integer`
  // u32 는 Copy trait를 구현한다.  
  let copied_integer = an_integer;

  println!("An integer: {:?}", copied_integer);
  println!("A boolean: {:?}", a_boolean);
  println!("Meet the unit value: {:?}", unit);

  // The compiler warns about unused variable bindings; these warnings can
  // be silenced by prefixing the variable name with an underscore
  let _unused_variable = 3_u32;

  // let noisy_unused_variable = 2_u32;
}

pub fn look_mutable_bindings() {
  let caller = std::panic::Location::caller();
  println!("caller: {:?}", caller);

  let _immutable_binding = 1;
  let mut mutable_binding = 1;

  println!("Before mutation: {}", mutable_binding);

  // Ok
  mutable_binding += 1;

  println!("After mutation: {}", mutable_binding);

  // Error!
  // _immutable_binding += 1;
  // FIXME ^ Comment out this line
}

pub fn look_binding_scope() {
  // This binding lives in the main function
  let long_lived_binding = 1;

  // This is a block, and has a smaller scope than the main function
  {
    // This binding only exists in this block
    let short_lived_binding = 2;

    println!("inner short: {}", short_lived_binding);
  }
  // End of the block

  // Error! `short_lived_binding` doesn't exist in this scope
  // println!("outer short: {}", short_lived_binding);
  // FIXME ^ Comment out this line

  // debug_assert_eq! , debug_assert!를 코딩할 때 사용한다. 테스트 시 반영된다.  
  debug_assert_eq!(long_lived_binding, 1);
  println!("outer long: {}", long_lived_binding);
}

// 섀도우 기능이 있지만 바람직하지는 않아 보인다.
pub fn look_variable_shadowing() {
    let shadowed_binding = 1;

    {
        println!("before being shadowed: {}", shadowed_binding);

        // This binding *shadows* the outer one
        let shadowed_binding = "abc";

        println!("shadowed in inner block: {}", shadowed_binding);
    }
    println!("outside inner block: {}", shadowed_binding);

    // This binding *shadows* the previous binding
    let shadowed_binding = 2;
    println!("shadowed in outer block: {}", shadowed_binding);
}

pub fn look_binding_freeze() {
    let mut _mutable_integer = 7i32;

    {
        // Shadowing by immutable `_mutable_integer`
        let _mutable_integer = _mutable_integer;

        // Error! `_mutable_integer` is frozen in this scope
        // _mutable_integer = 50;
        // FIXME ^ Comment out this line

        // `_mutable_integer` goes out of scope
    }

    // Ok! `_mutable_integer` is not frozen in this scope
    _mutable_integer = 3;
}
