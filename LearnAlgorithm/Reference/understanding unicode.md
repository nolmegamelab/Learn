# understanding unicode

## Unicode in detail 

### Every character is a number 

code point라고 불리는 고유한 값을 모든 문자에 할당한다. 

### Unicode encoding forms 

code point 전체를 표현하기위해 32비트가 필요하지만 인코딩 형식을 선택하여 더 적은 크기로 
표현할 수 있게 한다. UTF-8, UTF-16, UTF-32는 인코딩 형식이다.

### Character vs. code point

code point는 시퀀스에 따라 다른 캐릭터에 매핑될 수 있다. 

### Text elements 

text element는 code point 상위의 추상화이다. 

- Grapheme clusters
  - 캐릭터에 가까운 개념이다. 
  - boundary property value를 code point에 할당한다. 
  - 이에 따라 의미가 달라지고 합쳐져서 하나의 캐릭터가 되는 속성도 부여한다. 
  - break rule을 어기지 않는 속성을 갖는 코드 포인트들의 열은 하나의 그래핌 클러스터에 포함된다. 

- Words
  - 단어들도 경계 속성과 break rule로 결정한다. 
  - 그래핌이 아닌 워드를 만든다. 

### Normalization 

속성 값의 순서에 따라 그래핌 클러스터가 달라지는 문제를 해결하기 위해 4개의 정규 형식을 
정의하고 이를 지키도록 한다. 


## The STL 

### Containers

### Algorithms 

### Iterator 

### Concepts 

# Unicode 14.0 

https://www.unicode.org/versions/Unicode14.0.0/

## Introduction 

