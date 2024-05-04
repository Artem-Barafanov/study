#pragma once

namespace ABar {
	template<typename T>
	class ListStack {
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
		ListStack() noexcept {
			begin = new Node(T());
			end = new Node(T());
			begin->next = end;
			end->prev = begin;
		}
		ListStack(const ListStack&) = delete;
		ListStack& operator = (const ListStack&) = delete;
		~ListStack() noexcept {
			Node* tmp;
			while (begin != nullptr) {
				tmp = begin;
				begin = begin->next;
				delete tmp;
			}
		}
		void print() const noexcept {
			Node* tmp = begin->next;
			while (tmp != end) {
				std::cout << tmp->value << ' ';
				tmp = tmp->next;
			}
		}

		bool empty() const noexcept {
			if (begin->next == end) {
				return true;
			}
			return false;
		}
		void pop() noexcept {
			if (not empty()) {
				end->prev = end->prev->prev;
				delete end->prev->next;
				end->prev->next = end;
			}
		}
		void push(const T& value) noexcept {
			Node* new_node = new Node(value);
			new_node->prev = end->prev;
			new_node->next = end;
			end->prev->next = new_node;
			end->prev = new_node;
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
		T top() const noexcept {
			if (end->prev != begin) {
				return end->prev->value;
			}
		}
	};
}
