// mod coercions 

#[cfg(test)]
mod test {

  #[test]
  fn test_coercion() {
    // 타잎 변환이 동작하는 부분이 꽤 있으나 From trait로 구현해야 한다. 

    // 아래는 Trait의 impl이 coercion을 강제하지 않는 예이다. 

    trait Trait {}

    fn foo<X: Trait>(t: X) {}

    impl<'a> Trait for &'a i32 {}

    let t: &mut i32 = &mut 0;
    // foo로 t를 갖고 호출할 방법이 있는가? 
    // foo(t);
  }
}