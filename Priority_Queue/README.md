<div align="center">
  
  ![header](https://capsule-render.vercel.app/api?type=waving&color=timeAuto&height=180&section=header&text=Priority%20Queue&fontSize=70)
  ### 우선순위 큐
</div>

<br/>

## 🖥️ 개요

### 📌 우선순위 큐란?
- Queue + Data Priority
- 우선 순위가 높은 데이터가 먼저 빠져나가는 원리.
- 핵심: "데이터의 우선 순위를 무엇으로 잡을 것인가?"
- 데이터 들어온 시각을 우선순위로? => 일반적인 큐처럼 작동.
- 이용 분야 : `시뮬레이션 시스템` - 우선순위(사건의 시각), `네트워크 트래픽 제어`, `OS 작업 스케쥴링` etc.
- 구현 방법 : `Array`, `LinkedList`, **`Heap`**

### 📌 ADT
- 객체 : n개의 element형의 우선 순위를 가진 요소들의 모임
- 연산 : 
    > - **create()** : 우선순위 큐 생성 연산.
    > - **init(q)** : 우선순위 큐 q 초기화 연산.
    > - **is_empty(q)** : 우선순위 큐 q 공백 검사 연산.
    > - **is_full(q)** : 우선순위 큐 q 가득 찼는가 검사 연산.
    > - **insert(q,x)** : 우선순위 큐 q에 요소 x 추가 연산.
    > - **delete(q)** : 우선순위 큐로부터 가장 우선순위가 높은 요소 삭제 및 반환.
        > 최소 우선순위 큐 : min(우선순위) 기준.
        > 최대 우선순위 큐 : max(우선순위) 기준.
    > - **find(q)** : 우선순위가 가장 높은 요소 반환.

<br/>

## 🖥️ 구현 방법

### 📌 배열
- 정렬 x 배열의 경우?
    > 삽입 : 배열의 맨 끝에 새로운 요소 추가.<br/>
    > 삭제 : 가장 우선 순위가 높은 요소를 찾기 위해, 모든 요소 탐색.<br/><br/>
    > **시간복잡도**
    > - 삽입 : O(1)
    > - 삭제 : O(n)

- 정렬 O 배열의 경우?
    > 삽입 : 삽입 위치 탐색 + 삽입 위치 뒤의 요소들 이동 및 삽입<br/>
    > 삭제 : 맨 뒤 요소 삭제.<br/><br/>
    > **시간복잡도**
    > - 삽입 : O(n)
    > - 삭제 : O(1)

### 📌 연결 리스트
- 정렬 x 리스트의 경우?
    > 삽입 : 1번째 노드로 삽입(이게 유리하기 때문) + 헤드 포인터 변경 <br/>
    > 삭제 : 포인터를 따라 모든 노드 탐색.<br/><br/>
    > **시간복잡도** 
    > - 삽입 : O(1)
    > - 삭제 : O(n)

- 정렬 o 리스트의 경우?
    > 삽입 : 우선 순위 높은 요소 앞에 위치 + 삽입위치 탐색 필요.<br/>
    > 삭제 : 1번째 노드 삭제.<br/><br/>
    > **시간복잡도**
    > - 삽입 : O(n)
    > - 삭제 : O(1)

### 📌 히프
[개요]
- 우선순위 큐를 위해 특별히 제작된 자료 구조.
- 완전 이진 트리의 일종
- **일종의 느슨한 정렬 상태 유지**
- 완전 정렬은 아니지만, 정렬이 안된 것도 아닌 상태.
- 시간복잡도(삽입 및 삭제) : O(log n)

[개념]
- 여러 개의 값들 중에서 가장 큰값 또는 가장 작은값을 빠르게 찾아내는 자료구조.
- 다음 조건을 통해 종류가 나뉨.
    - Key(부모노드) >= Key(자식노드) : `최대 히프` (Max Heap)
    - Key(부모노드) <= Key(자식노드) : `최소 히프` (Min Heap)
- 완전 이진 트리의 특성 + 중복값 허용. (이진 탐색 트리에서는 중복값 허용 x)

[구현]
- `배열` : 완전 이진 트리 -> 각 노드에 차례대로 넘버링. (이를 배열의 인덱스로 적용.)
- 쉬운 구현을 위해, **배열의 1번째 인덱스인 0은 사용하지 않음.**
- 자식노드와 부모노드 인덱스 파악?
    > - Left Children Index = (Parent Index) * 2
    > - Right Children Index = (Parent Index) * 2 + 1
    > - Parent Index = (Children) / 2 <br/><br/>
    > 
    > **K진 트리의 인덱스 파악?**
    > - Children Index = (i*k) - (k-2)
    > - Parent Index = (i+k-2) / k

### 📌 히프 주요연산
- `Max Heap`을 기준으로 설명.

* * *

**[삽입연산] - Insert Function**
- `부모 노드와 비교하여 새로운 요소의 삽입 위치를 발견할 때까지 반복 탐색`
- *초기상태 및 1번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/f6f9e937-e9f7-47d3-8c35-08b781e89691" width="300" height="300" alt="insert_process_01">
  - 배열로 구현된 히프이기에, 각 노드에 넘버링(=배열 인덱스)가 가능하다.
  - 번호순으로 가장 마지막 위치에 이어서 새로운 요소 8이 삽입.(Node Number: 11)

- *2번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/e37223ed-0504-4aa1-ba52-6dc7be56cc73" width="300" height="300" alt="insert_process_02">
  - 부모노드 4 < 삽입노드 8 이므로, 교환.

- *3번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/c73577bd-1106-41e2-952f-6f02a98adca0" width="300" height="300" alt="insert_process_03">
  - 부모노드 7 < 삽입노드 8 이므로, 교환.

- *4번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/4e60ec20-b685-4f76-b131-a8928d4392ae" width="300" height="300" alt="insert_process_04">
  - 부모노드 9 > 삽입노드 8 이므로, 교환하지 않음.

- *의사 코드*
  ```
  insert_function(A,key):

  1. heap_size <- heap_size + 1; // 히프 크기 하나 증가.
  2. i <- heap_size; // 증가된 히프 위치에 새로운 노드 삽입.
  3. A[i] <= key; 
  4. while i!=1 and A[i] > A[PARENT(i)] do // i가 루트노드가 아니고, i번째노드가 i의 부모노드보다 크면
  5.   A[i] <-> A[PARENT]; // i번째 노드와 부모노드 스위치.
  6.   i <- PARENT(i); // 한 레벨 위로 올림.(높이 상승)
  ```

* * *

**[삭제연산] - Delete Function**
- `자식 노드와 비교하여 새로운 요소의 삽입 위치를 발견할 때까지 반복 탐색`
- *초기상태 및 1번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/025c661c-8e60-4549-8f06-26fc24855c04" width="300" height="300" alt="delete_process_01">
  - 먼저 루트 노드 삭제.
  - 빈 루트 노드 자리에 히프의 마지막 노드를 가져온다.

- *2번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/6d20101a-8ffc-4f46-bc02-62900463fdc4" width="300" height="300" alt="delete_process_02">
  - 자식 중에서 큰 값과 교환된다.(최대 히프)
  - 새로운 루트인 3과 자식 노드 8이 교환.

- *3번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/f24d0aa0-0684-4984-8053-d32c533452cc" width="300" height="300" alt="delete_process_03">
  - 오른쪽 자식노드인 7과 교환된다.

- *4번째 단계*
  - <img src="https://github.com/jaekyungshon/Basic-Algorithm-Study/assets/61006212/debc05fe-0577-4006-90bf-e96effa310c3" width="300" height="300" alt="delete_process_04">
  - 단말 노드이므로, 더 이상 교환이 일어나지 않는다.
  - 비단말 노드이고, 자식노드들 보다 값이 큰 경우도, 더 이상 교환이 일어나지 않는다.

- *의사 코드*
  ```
  delete_function(A):

  1. item <- A[i]; // root node 값 반환을 위한 item 변수.
  2. A[1] <- A[heap_size]; // 말단 노드를 루트 노드로 옮김.
  3. heap_size <- heap_size - 1; // 히프의 크기 하나 감소.
  4. i <- 2; // 루트의 왼쪽 자식부터 비교 시작.
  5. while i<= heap_size do // 히프트리를 벗어나지 않으면
  6.   if i < heap_size and A[i+1] > A[i] // 오른쪽 자식이 더 크면
  7.     then largest <- i+1; // 오른쪽 자식 선택
  8.     else largest <- i; // 그렇지 않으면, 왼쪽 자식 선택
  9.   if A[PARENT(largest)] > A[largest] // 부모노드가 더 크면
  10.    then break; // 중지
  11.  A[PARENT(largest)] <-> A[largest]; // 9번 조건 반대면, largest와 largest 부모노드 교환.
  12.  i <- CHILD(largest); // 한 레벨 밑으로 내려간다.
  13.
  14. return item; // 최대값 반환.
  ```


* * *

<br/>

## 🖥️ 우선순위 큐(히프) 활용
- `머신 스케쥴링` : `LPT Algorithm`
- `허프만 코드`

### 📌 Machine Schedling
- 배경
  > <p>어떤 공장에 동일한 기계가 m개 있고, 처리해야할 작업은 n개 존재한다.</p>
  > <p>각 작업이 필요로 하는 기계의 사용시간이 다른 경우로 가정.</p>
  > <p>목표: 모든 기계를 작동하여, 가장 최소의 시간 안에 작업들을 종료시키는 것</p>
  > <p>Note) 응용분야 : 서버 작업 분배 etc</p>

- 해결법
  - Longest pro-cessing time first
  - **LPT 알고리즘** : `근사 해 찾기`, `가장 긴 작업을 우선적으로 할당`
  - 데이터의 우선순위 : 가장 짧은 종료 시간을 가진 기계. (최소 히프)

- 구현 알고리즘
  1. 내림차순으로 정렬된 작업 n개를 담는 배열 준비. (히프 정렬 등 이용)
  2. 기계의 종료시간들을 Min Heap에 삽입.
  3. 삭제 후 반환된 요소인 기계에 작업 할당.
  4. 할당된 기계의 종료시간 갱신.
  5. 갱신된 기계를 다시 Min Heap에 삽입.


### 📌 Huffman Codes
