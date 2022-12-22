// mod ownership 
// https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html

#![allow(unused_variables)]

pub fn look_scope() {
  // rule 1. each value has an owner 
  // rule 2. each value has only one owner at a time 
  // rule 3. if the owner goes out of scope, the value is dropped 
  // owner는 변수이다. 
  {
    let s = "Hello";

    println!("s:{}", s);
  }
  // s is dropped
}

pub fn look_string() {

  let mut s = String::from("Hello");
  s.push_str(" world!");

  println!("{}", s);

  // 이렇게 일반 변수처럼 move할 수 있다. 
  let ns = s;

  // 여기서 더 이상 사용할 수 없게 된다. 
  // println!("{}", s);

  let rs = &ns;
  println!("rs:{}", rs);

  // rust는 깊은 복사를 자동으로 구현하지 않는다. 

  let s3 = ns.clone();
  println!("s3:{}", s3);

  // Copy trait와 primitive 타잎들의 Copy 특성
  // Drop 되는 것들은 Copy 될 수 없다. ==> 스택에 있는 것들을 복사하자는 의도
}


pub fn look_move_or_copy() {
    let s = String::from("hello");  // s comes into scope

    takes_ownership(s);             // s's value moves into the function...
                                    // ... and so is no longer valid here

    let x = 5;                      // x comes into scope

    makes_copy(x);                  // x would move into the function,
                                    // but i32 is Copy, so it's okay to still
                                    // use x afterward

} // Here, x goes out of scope, then s. But because s's value was moved, nothing
  // special happens.

fn takes_ownership(some_string: String) { // some_string comes into scope
    println!("{}", some_string);
} // Here, some_string goes out of scope and `drop` is called. The backing
  // memory is freed.

fn makes_copy(some_integer: i32) { // some_integer comes into scope
    println!("{}", some_integer);
} // Here, some_integer goes out of scope. Nothing special happens.

pub fn look_return_owership() {
  let s1 = take_ownership_from();
  
  let v1 = copy_from();
}

fn take_ownership_from() -> String {
  let s = String::from("simple value");
  s
}

fn copy_from() -> i32 {
  let iv = 32; 
  iv
}

pub fn look_references_1() {

  // 여기서 mut가 아니면 mut 참조를 얻을 수 없다. 
  let mut s = String::from("Hello");
  let len = calculate_length(&s);

  println!("{}'s length: {}", s, len);

  add_world(&mut s);
  println!("{}", s);
}

fn calculate_length(s: &String) -> usize {
  s.len()
}

fn add_world(s: &mut String) -> () {
  // 참조는 빌리는 것. 쓰기 빌리기와 읽기 빌리기가 있다.
  s.push_str(", world");
}

// 이후 slice에 대한 설명과 예제 코드들이 있다. 
// 슬라이스는 러스트에서 중요하게 사용되는 구조이다. 

