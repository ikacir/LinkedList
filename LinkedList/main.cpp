#include <iostream>


struct Node {
	int data;
	struct Node *next;
};

Node *buildList(int arr[], int size) {
	Node *p = new Node;
	Node *head = p;

	int i = 0;
	while (p != NULL) {
		p->data = arr[i];
		p->next = new Node;
		if (i == size - 1) {
			p->next = NULL;
		}
		p = p->next;
		i++;
	}

	return head;
};

Node *insert(Node *head, int data, int position) {
	Node *nodeToInsert = new Node;
	nodeToInsert->data = data;
	Node *newHead = head;

	if (position == 0) {
		nodeToInsert->next = head;
		newHead = nodeToInsert;
	}
	else {
		int i = 0;
		while (head != NULL) {
			if (i == position - 1) {
				nodeToInsert->next = head->next;
				head->next = nodeToInsert;
			}
			head = head->next;
			i++;
		}
	}
	return newHead;
}

Node *mergeLists(Node* headA, Node* headB) {
	// swap the heads if the first node of headB is < that of headA, the
	// implementation depends on the first node of headA being the smallest.
	if (headB->data < headA->data) {
		Node *temp = headA;
		headA = headB;
		headB = temp;
	}

	Node *mergedHead = headA;
	// Now we know that headA->data is always the smallest,
	// so begin looking at the next node.
	Node *tempA = headA->next;
	Node *tempB = headB;

	while (headA != NULL) {
		if (tempB->data < tempA->data) {
			headA->next = tempB;
			tempB = (tempB->next != NULL) ? tempB->next : tempA;
		}
		else if (tempB->data == tempA->data) {
			// both temp pointers have reached the last node,
			// connect the last node then terminate loop.
			headA->next = tempA;
			break;
		}
		else {
			headA->next = tempA;
			tempA = (tempA->next != NULL) ? tempA->next : tempB;
		}
		headA = headA->next;
	}

	return mergedHead;
}

void printList(Node *head) {
	while (head != NULL) {
		std::cout << head->data << (head->next == NULL ? " -> N" : " -> ");
		head = head->next;
	}
	std::cout << std::endl;
}

void reversePrint(Node *head) {
	Node *copy = head;

	while (head != NULL) {
		if (head->next == NULL) {
			std::cout << head->data << (head->next == NULL ? " -> N" : " -> ");
		} else if (head->next->next == NULL) {
			std::cout << head->next->data << (head->next == NULL ? " -> N" : " -> ");
			head->next = NULL;
			head = copy;
			continue;
		}
		head = head->next;
	}
	std::cout << std::endl;
}

void main() {
	//int arr1[] = {3, 4, 5, 6, 11, 12};
	//int size1 = sizeof(arr1)/sizeof(arr1[0]);
	//printList(insert(buildList(arr1, size1), 1, 2));
	int arrA[] = { 2, 4, 7, 8, 11 };//{ 1, 3, 5, 6, 9, 10 };
	int sizeA = sizeof(arrA) / sizeof(arrA[0]);
	Node *listA = buildList(arrA, sizeA);
	int arrB[] = { 1, 3, 5, 6, 9, 10, 12 };//{ 2, 4, 7, 8 };
	int sizeB = sizeof(arrB) / sizeof(arrB[0]);
	Node *listB = buildList(arrB, sizeB);
	printList(mergeLists(listA, listB));
	//reversePrint(listB);
}