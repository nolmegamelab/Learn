use std::collections::HashMap;

/// HashMap은 c++이나 c#에 필적하는 구현을 갖고 있다. 
/// drain, filter와 같은 함수도 있으며 함수형 스타일로 작업할 수 있다.  
/// hasher 함수를 지정할 수 있으며 capacity도 미리 지정 가능하다.
fn use_case_1() {
    let mut dic_1= HashMap::new();

    dic_1.insert(String::from("Ha"), 1);
    dic_1.insert(String::from("Ho"), 2);

    for key in dic_1.keys() {
        println!("key:{}, val:{}", key, dic_1[key]);
    }

    if dic_1.contains_key("Nope") {
        println!("dic_1 contains Nope");
    } else {
        println!("dic_1 does not contain Nope");   
    }
}

fn use_case_2() {

    let name = String::from("kdpark");

    // String은 Vec<u8>으로 구현된다. 
    // 매크로, 함수 등의 기법을 간결하게 잘 보여준다. 

    let s = name.chars();

}

fn main() {
    use_case_1();
    use_case_2();
}
