#pragma once

template <typename T, size_t size>
class QueueLoop
{
public:
	QueueLoop()
	{
		for (size_t i = 0; i < size; i++)
		{
			array_[i] = T{}; // Default value for each element in array_
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

/// <summary>
/// Add a value to the back of the queue. If the queue has reached the end, it will loop back to 
/// the start and ovveride that.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="size"></typeparam>
/// <param name="value"></param>
template<typename T, size_t size>
inline void QueueLoop<T, size>::Enqueue(T value)
{
	if (back_ > size_)
		back_ = 0;

	array_[back_] = value;
	back_++;
}

/// <summary>
/// Remove the oldest value from the queue, and go on to the next one.
/// In actuallity, it just moves on, and doesn't remove it.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="size"></typeparam>
/// <returns></returns>
template<typename T, size_t size>
inline T& QueueLoop<T, size>::Dequeue()
{
	if (front_ > size_)
		front_ = 0;
	auto& return_value = array_[front_];
	front_++;
	return return_value;
}

/// <summary>
/// Get a reference to the array used to store all the data.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="size"></typeparam>
/// <returns></returns>
template<typename T, size_t size>
inline const T(&QueueLoop<T, size>::GetQueue() const)[size]
{
	return array_;
}
