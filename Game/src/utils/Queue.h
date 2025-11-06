#pragma once

template <typename T, size_t size>
class Queue
{
public:
	Queue()
	{
		for (size_t i = 0; i < size; i++)
		{
			array_[i] = T{} // Default value for each element in array_
		}
	}
	void Enqueue(T value);
	T& Dequeue();
	// Absolute mishmash, returns a reference to an array, but also needs the size of the array to pass it properly. Makes head hurt.
	const T (&GetQueue() const)[size];  // Const has to be inside the brackets otherwise it throws an error???
private:
	T array_[size];
	const size_t size_ = size; // this won't change later
	size_t front_ = 0; // Where to dequeue from
	size_t back_ = 0; // Where to queue to
};

// Inline is used because these templates are declared outside the class definition, and would otherwise count
// as a normal function definition, and would cause errors if it were included in multiple places.

template<typename T, size_t size>
inline void Queue<T, size>::Enqueue(T value)
{
	if (front_ > size)
		front_ = 0;

	array_[front_] = value;
	front_++;
}

template<typename T, size_t size>
inline T& Queue<T, size>::Dequeue()
{
	
	// TODO: insert return statement here
}

template<typename T, size_t size>
inline const T(&Queue<T, size>::GetQueue() const)[size]
{
	return array_;
}
