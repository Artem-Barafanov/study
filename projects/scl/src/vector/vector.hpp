#pragma once
#include <iostream>

namespace ABar {
	template <typename T>
	class Vector {
	private:
		T* arr;
		std::size_t capacity = 2;
		std::size_t size = 0;
	public:
		Vector() noexcept {
			arr = new T[capacity];
		}
		Vector(const Vector&) = delete;
		Vector& operator = (const Vector&) = delete;
		~Vector() noexcept {
			delete[] arr;
		}

		void push_back(const T& value) noexcept {
			if (size + 1 > capacity) {
				capacity *= 2;
				T* vec = new T[capacity];
				for (int i = 0; i < size; i++) {
					vec[i] = arr[i];
				}
				size += 1;
				vec[size - 1] = value;
				delete[] arr;
				arr = vec;
			}
			else {
				arr[size] = value;
				size += 1;
			}
		}

		bool has_item(const T& value) const noexcept {
			for (int i = 0; i < size; i++) {
				if (arr[i] == value) {
					return true;
				}
			}
			return false;
		}

		bool insert(const int position, const T& value) {
			if (position >= 0 && position < size && (size + 1) <= capacity) {
				size += 1;
				for (int i = size - 1; i > position; i--) {
					arr[i] = arr[i - 1];
				}
				arr[position] = value;
				return true;
			}
			else {
				return false;
			}
		}

		void print() const noexcept {
			for (int i = 0; i < size; i++) {
				std::cout << arr[i] << ' ';
			}
		}

		bool remove_first(const T& value) noexcept {
			for (int i = 0; i < size; i++) {
				if (arr[i] == value) {
					for (int j = i + 1; j < size; j++) {
						arr[j - 1] = arr[j];
					}
					size -= 1;
					return true;
				}
			}
			return false;
		}
		std::size_t size_arr() const noexcept {
			return size;
		}

		T& operator[](std::size_t index) {
			return arr[index];
		}
	};
}

