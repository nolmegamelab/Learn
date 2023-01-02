# box 

let v = Box::new(3);
let mut v = Box::new(Type::new());
v.field = value;

Box, NonNull, Unique, Pin, ptr은 모두 포인터 처리를 도와 주는 클래스들이다.   

- NonNull은 널이 아닌 포인터를 담는 그릇으로 사용 
- Box는 raw pointer의 바로 다음 단계 스마트 포인터 
- NonNull, Box, Option으로 linked_list가 구현되었다. 









