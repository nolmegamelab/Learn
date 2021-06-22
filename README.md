# Learn

Learning archive


## git credential 

생각보다 보안은 훨씬 복잡하다. 시간에 따라 끝없이 변한다. 

윈도우 자격 증명에서 제거하고 여러 가지 방법을 시도했으나 
여전히 github 로그인으로는 실패가 난다. 

git config --global credential.helper wincred

위 명령어를 실행하고 나서 괜찮아졌다. 윈도우 자격 증명을 
사용하게 하면 해당 인증 정보와 연결하여 자동으로 로그인한다. 

