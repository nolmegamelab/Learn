# Learn PBR (Physically Based Rendering) 

PBR은 큰 주제이다. 기하를 다루고 기본 렌더링을 하는 알고리즘부터 차근차근 살핀다. 

bgfx와 glm을 근간에 두고 여기에 PBR 알고리즘을 테스트 한다. 책에서 제공하는 내용과
bgfx와 glm에서 배울 수 있는 내용을 토대로 그래픽스를 익혀 나간다. 

bgfx는 c 기반으로 매우 간결한 렌더링 인터페이스를 갖고 있다. 따라서, 여기에 기반하여 
자체적인 c++ 렌더링을 쌓기가 좋아 보인다. 어떤 걸 선택하더라도 아쉬움은 있다. 
그런 아쉬움은 주로 나의 부족함에서 기인한다. 되도록 바닥에서 쌓아야 하나 
효율적인 진행을 고려해야 한다. 충분히 이해하나 너무 구현에 집착하지 않도록 한다. 

## 진행 

- bgfx의 빌드와 예제 실행 
- glm 필요시 통합 
- PBR 하나씩 진행 
  - visualization 중심으로 진행 
  - 그래픽스 튜토리얼 프로젝트 
  - 그리고 움직이면 된다. 수학이 중요한 것이 아니다. 그게 수학이다. 

 
## 빌드 

아래 링크에서 git:: 대신 https::를 사용해야 한다. 

git clone git://github.com/bkaradzic/bx.git
git clone git://github.com/bkaradzic/bimg.git
git clone git://github.com/bkaradzic/bgfx.git

빌드 에러가 나오는데 원인이 무엇인가? 

2개 프로젝트 외에는 잘 빌드된다. 

