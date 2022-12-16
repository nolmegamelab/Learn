use std::fmt; 

// file structuring
// - use 
// - struct, enums 
// - impls 
// - module functions
// 

// derive를 통해 Debug 기능을 매크로 구현한다.
#[derive(Debug)]
struct DebugPrintable(i32);

#[derive(Debug)]
struct Person<'a> {
  name: &'a str,
  age: u8
}

struct DetailedInt(i32);

struct Point {
  x : f32, 
  y : f32,
}

impl fmt::Display for DetailedInt {
  // fmt::Display trait의 함수가 fmt이다. 
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "{}", self.0)
  }
}

impl fmt::Display for Point {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "x:{}, y:{}", self.x, self.y)
  }
}

pub fn ex_debug_print() {
  println!("Debug: {:?}", DebugPrintable(32));
  println!("{1:?} {0:?}", "one", "two");
}

// 러스트는 매우 강력한 매크로 시스템을 갖추고 있어 
// derive(Debug)로 충분한 정보를 출력할 수 있다.
pub fn ex_debug_struct() {

  let name = "dong";
  let age = 54;
  let p1 = Person { name: name, age: age };

  // Debug trait를 통해 접근하는 경우 dead code로 인지
  println!("Person: {:?}", p1);
  // 직접 사용해야 dead code가 아닌 것으로 판단한다.
  println!("Person.name: {:?}, Person.age: {:?}", p1.name, p1.age);
}

pub fn ex_custom_display() {
  let iv = DetailedInt(33);
  // DetailedInt가 Debug를 상속하지 않고, Display trait를 구현하므로 
  // {:?}이 아닌 {}를 사용하여 직접 fmt를 호출한다. 
  // 이렇게 매크로 사슬을 통해 재사용 가능한 범위를 늘려간다.
  println!("{}", iv);
}

pub fn ex_print_point() {
  println!("{}", Point{ x: 3.1, y: 3.3 });
}