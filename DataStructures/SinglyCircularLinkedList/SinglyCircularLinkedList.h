#pragma once

#include <iostream>

using namespace std;

#define endl '\n'

// 단일 환형 연결 리스트의 노드 구조체
template <typename T>
struct Node
{
    T Data; // 노드에 저장할 데이터
    Node* Next; // 다음 노드를 가리키는 포인터

    // 생성자: 데이터 초기화 및 next를 nullptr로 설정
    Node(T InValue) : Data(InValue), Next(nullptr)
    {
    }
};

// 단일 환형 연결 리스트 클래스
template <typename T>
class SinglyCircularLinkedList
{
public:
    // 생성자: head를 nullptr로 초기화하여 빈 리스트 생성
    SinglyCircularLinkedList() : Head(nullptr)
    {
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~SinglyCircularLinkedList()
    {
        if (Head == nullptr) // 리스트가 비어있으면 종료
            return;

        Node<T>* currNode = Head->Next; // 두 번째 노드부터 시작

        while (currNode != Head) // head로 돌아올 때까지 반복
        {
            Node<T>* tempNode = currNode; // 현재 노드를 임시 저장

            currNode = currNode->Next; // 다음 노드로 이동

            delete tempNode; // 저장된 노드 삭제
        }

        delete Head; // 마지막으로 Head 삭제

        Head = nullptr; // Head 초기화
    }

    // 리스트 끝에 노드 추가
    void Append(T Data)
    {
        Node<T>* newNode = new Node<T>(Data); // 새 노드 생성

        if (Head == nullptr) // 리스트가 비어있으면
        {
            Head = newNode; // head를 새 노드로 설정

            Head->Next = Head; // 새 노드의 next를 자신으로 연결 (순환)

            return;
        }

        Node<T>* currNode = Head; // 순회용 포인터

        while (currNode->Next != Head) // 마지막 노드까지 이동
            currNode = currNode->Next;

        currNode->Next = newNode; // 마지막 노드의 next를 새 노드로 연결

        newNode->Next = Head; // 새 노드의 next를 head로 설정 (순환)
    }

    // 리스트 처음에 노드 추가
    void Prepend(T Data)
    {
        Node<T>* newNode = new Node<T>(Data); // 새 노드 생성

        if (Head == nullptr) // 리스트가 비어있으면
        {
            Head = newNode; // head를 새 노드로 설정

            Head->Next = Head; // 새 노드의 next를 자신으로 연결 (순환)

            return;
        }

        Node<T>* currNode = Head; // 순회용 포인터

        while (currNode->Next != Head) // 마지막 노드까지 이동
            currNode = currNode->Next;

        newNode->Next = Head; // 새 노드의 next를 기존 head로 설정

        currNode->Next = newNode; // 마지막 노드의 next를 새 노드로 연결

        Head = newNode; // head를 새 노드로 업데이트
    }

    // 특정 값의 노드 삭제
    void Delete(T Data)
    {
        if (Head == nullptr) // 리스트가 비어있으면 종료
            return;

        Node<T>* currNode = Head; // 순회용 포인터

        Node<T>* prevNode = nullptr; // 이전 노드 추적용 포인터

        // 단일 노드일 경우
        if (Head->Data == Data and Head->Next == Head)
        {
            delete Head; // Head 삭제

            Head = nullptr; // Head 초기화

            return;
        }

        // 삭제할 노드 탐색
        do
        {
            prevNode = currNode; // 현재 노드를 이전 노드로 설정

            currNode = currNode->Next; // 다음 노드로 이동
        }
        while (currNode != Head and currNode->Data != Data);

        if (currNode == Head and currNode->Data != Data) // 값이 없으면 종료
            return;

        if (currNode == Head) // Head 노드 삭제
        {
            Node<T>* lastNode = Head; // 마지막 노드 찾기

            while (lastNode->Next != Head)
                lastNode = lastNode->Next;

            lastNode->Next = Head->Next; // 마지막 노드의 next를 새 head로 연결

            Head = Head->Next; // head를 다음 노드로 이동

            delete currNode; // 삭제

            return;
        }

        // 중간 또는 마지막 노드 삭제
        prevNode->Next = currNode->Next; // 이전 노드와 다음 노드 연결

        delete currNode; // 노드 삭제
    }

    // 리스트 출력
    void Print()
    {
        if (Head == nullptr) // 리스트가 비어있으면
        {
            cout << "List is empty" << endl;

            return;
        }

        Node<T>* currNode = Head; // 순회용 포인터

        cout << "Circular List: ";

        do
        {
            cout << currNode->Data << " -> "; // 현재 노드 데이터 출력

            currNode = currNode->Next; // 다음 노드로 이동
        }
        while (currNode != Head); // head로 돌아오면 종료

        cout << "(Head)" << endl;
    }

private:
    Node<T>* Head; // 리스트의 첫 노드 (순환의 시작점)
};
