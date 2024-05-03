#pragma once

#include <cstddef>
#include <iostream>

namespace ABar {
	template <typename T>
	class DoublyLinkedList {
	private:
		class Node {
		public:
			T value;
			Node* prev = nullptr;
			Node* next = nullptr;

			Node(const T& value) : value(value) {}

			Node(const Node&) = delete;
			Node& operator = (const Node&) = delete;
		};
		Node* begin = nullptr;
		Node* end = nullptr;
	public:
		DoublyLinkedList() noexcept {
			begin = new Node(T());
			end = new Node(T());
			begin->next = end;
			end->prev = begin;
		}
		DoublyLinkedList(const DoublyLinkedList&) = delete;
		DoublyLinkedList& operator = (const DoublyLinkedList&) = delete;
		~DoublyLinkedList() noexcept {
			Node* tmp;
			while (begin != nullptr) {
				tmp = begin;
				begin = begin->next;
				delete tmp;
			}
		}

		void push_back(const T& value) noexcept {
			Node* new_node = new Node(value);
			new_node->prev = end->prev;
			new_node->next = end;
			end->prev->next = new_node;
			end->prev = new_node;
		}

		bool has_item(const T& value) const noexcept {
			Node* tmp = begin->next;
			while (tmp != nullptr) {
				if (tmp->value == value) {
					return true;
				}
				tmp = tmp->next;
			}
			return false;
		}

		void print() const noexcept {
			Node* tmp = begin->next;
			while (tmp != end) {
				std::cout << tmp->value << ' ';
				tmp = tmp->next;
			}
		}
		bool remove_first(const T& value) noexcept {
			Node* tmp = begin->next;
			while (tmp->value != value && tmp != end) {
				tmp = tmp->next;
			}
			if (tmp == end) {
				return false;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				return true;
			}
		}

		std::size_t size() const noexcept {
			std::size_t k = 0;
			Node* tmp = begin->next;
			while (tmp != end) {
				k++;
				tmp = tmp->next;
			}
			return k;
		}
	};
}

