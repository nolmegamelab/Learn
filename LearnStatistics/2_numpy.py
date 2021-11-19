import numpy as np 

a1 = np.ndarray(shape=(2, 2)) # 랜덤 값으로 초기화 
print(a1)
print(a1[0])
print(a1[1])
print(a1[0][1])

a2 = np.ndarray(shape=(2, 2, 3)) # 랜덤 값으로 초기화 
# 3개의 값을 갖는 열을 2개 갖는 행렬을 2개 갖는다. 
print(a2)
print(a2[0]) # 제일 바깥 쪽에 접근한다. 
a2[0][0] = [1, 2, 3]
print(a2[0][1]) # 제일 바깥 쪽에 접근한다. 

a3 = a2.reshape(2, 6)   
print(a3)

a4 = np.arange(20).reshape(2, 10)
print(a4)

a5 = a4.reshape(5, 2, 2)
print(a5)

# reshape
a6 = np.ravel(a5, order='F')
print(a6)

# ipython이 연습에 더 적절하다. 

