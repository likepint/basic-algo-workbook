#pragma once

#include <iostream>

using namespace std;

#define endl '\n'

// 단일 연결 리스트의 노드 구조체
template <typename T>
struct Node
{
    T Data; // 노드에 저장할 데이터
    Node* Next; // 다음 노드를 가리키는 포인터

    // 생성자: 데이터 초기화 및 다음 포인터를 nullptr로 설정
    Node(T InValue) : Data(InValue), Next(nullptr)
    {
    }
};

// 단일 연결 리스트 클래스
template <typename T>
class SinglyLinkedList
{
public:
    // 생성자: head를 nullptr로 초기화하여 빈 리스트 생성
    SinglyLinkedList() : Head(nullptr)
    {
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~SinglyLinkedList()
    {
        while (Head != nullptr) // head가 nullptr가 될 때까지 반복
        {
            Node<T>* tempNode = Head; // 현재 head 노드를 임시로 저장

            Head = Head->Next; // head를 다음 노드로 이동

            delete tempNode; // 저장된 노드 삭제
        }
    }

    // 리스트 끝에 노드 추가
    void Append(T Data)
    {
        Node<T>* newNode = new Node<T>(Data); // 새 노드 생성

        if (Head == nullptr) // 리스트가 비어있으면
        {
            Head = newNode; // head를 새 노드로 설정

            return;
        }

        Node<T>* current = Head; // 순회용 포인터

        while (current->Next != nullptr) // 마지막 노드까지 이동
            current = current->Next;

        current->Next = newNode; // 마지막 노드의 next를 새 노드로 연결
    }

    // 리스트 처음에 노드 추가
    void Prepend(T Data)
    {
        Node<T>* newNode = new Node<T>(Data); // 새 노드 생성

        newNode->Next = Head; // 새 노드의 next를 기존 head로 설정

        Head = newNode; // head를 새 노드로 업데이트
    }

    // 특정 값의 노드 삭제
    void Delete(T Data)
    {
        if (Head == nullptr) return; // 리스트가 비어있으면 종료

        if (Head->Data == Data) // head 노드가 삭제 대상이면
        {
            Node<T>* temp = Head; // head를 임시 저장

            Head = Head->Next; // head를 다음 노드로 이동

            delete temp; // 저장된 노드 삭제

            return;
        }

        Node<T>* current = Head; // 순회용 포인터

        while (current->Next != nullptr and current->Next->Data != Data) // 삭제 대상 탐색
            current = current->Next;

        if (current->Next != nullptr) // 삭제 대상이 존재하면
        {
            Node<T>* temp = current->Next; // 삭제할 노드를 임시 저장

            current->Next = temp->Next; // 다음 노드로 연결

            delete temp; // 노드 삭제
        }
    }

    // 리스트 출력
    void Print()
    {
        Node<T>* current = Head; // 순회용 포인터

        while (current != nullptr) // 리스트 끝까지 순회
        {
            cout << current->Data << " -> "; // 현재 노드 데이터 출력

            current = current->Next; // 다음 노드로 이동
        }

        cout << "nullptr" << endl; // 끝 표시
    }

private:
    Node<T>* Head; // 리스트의 첫 번째 노드를 가리키는 포인터
};
