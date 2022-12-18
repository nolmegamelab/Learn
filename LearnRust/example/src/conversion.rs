// mod conversion

use std::convert::From;
use std::convert::TryFrom;
use std::convert::TryInto;
#[derive(Debug)]
struct Number {
    value: i32,
}

#[derive(Debug, PartialEq)]
struct EvenNumber(i32);

impl From<i32> for Number {
    fn from(item: i32) -> Self {
        Number { value: item }
    }
}

impl TryFrom<i32> for EvenNumber {
    type Error = ();

    fn try_from(value: i32) -> Result<Self, Self::Error> {
        if value % 2 == 0 {
            Ok(EvenNumber(value))
        } else {
            Err(())
        }
    }
}

pub fn look_from_num() {
    let num = Number::from(30);
    println!("My number is {:?} via from", num);
}

pub fn look_into_num() {
    let v = 5;
    // Try removing the type annotation
    // return 타잎을 추론하고 From을 사용하여 변환한다. 
    let num: Number = v.into();
    println!("My number is {:?} via into", num);
}

pub fn look_try_from() {
    // TryFrom
    debug_assert_eq!(EvenNumber::try_from(8), Ok(EvenNumber(8)));
    debug_assert_eq!(EvenNumber::try_from(5), Err(()));

    // TryInto

    let result: Result<EvenNumber, ()> = 8_i32.try_into();
    debug_assert_eq!(result, Ok(EvenNumber(8)));

    let result: Result<EvenNumber, ()> = 5_i32.try_into();
    debug_assert_eq!(result, Err(()));
}

pub fn look_parse_from_string() {
    let parsed: i32 = "5".parse().unwrap();
    let turbo_parsed = "10".parse::<i32>().unwrap();

    let sum = parsed + turbo_parsed;
    println!("Sum: {:?}", sum);

    // f32는 FromStr trait를 구현하고 이를 적용하여 parse한다. 
    let turbo_parsed = "10.5".parse::<f32>().unwrap();
    // unwrap은 Result<T, E>의 함수로 Err일 경우 unwrap_failed를 호출하고 panic이 불린다.   
    println!("f32: {:?}", turbo_parsed);
}
