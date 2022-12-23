# drop flags 

러스트가 drop을 처리할 때 플래그로 관리한다. 어떻게 찾았을까? 소스 코드? 

```rust 
let mut x = Box::new(0); // x was uninit; just overwrite.
let mut y = x;           // y was uninit; just overwrite and make x uninit.
x = Box::new(0);         // x was uninit; just overwrite.
y = x;                   // y was init; Drop y, overwrite it, and make x uninit!
                         // y goes out of scope; y was init; Drop y!
                         // x goes out of scope; x was uninit; do nothing.
```

위와 같이 설명하려는 노력은 언어를 이해하는 좋은 방법이다. 마치, 도널드 누쓰의 
MIX 코드를 보는 듯 하다. 

drop 플래그는 스택 변수로 관리한다. 이전에는 Drop을 구현하는 타잎의 필드로 있었다.


