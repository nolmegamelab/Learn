// mod learn_types 
// 타잎 관련 실험실로 한다. 

pub fn print_type_of<T>(_ : &T) {
  // generic function과 type에 대한 아규먼트 지정이 ::<T> 형식이다. 
  println!("{}", std::any::type_name::<T>());
}

pub fn check_array_types() {

  let sa_1 = [1, 2, 3];

  // what is type of sa_1?
  print_type_of(&sa_1); // [i32; 3] 이다. 즉 배열이다. 

  for v in sa_1.iter() {
    print_type_of(v);     // v의 타잎은 &i32이다. 
    println!("{}", v);
  }

  print_type_of(&sa_1.iter());  // sa_1.iter()는 core::slice::iter::Iter<i32>이다. 
}