#include "FPSTracker.h"
#include <algorithm> // For std::copy and std::sort
#include "Common.h"

FPSTracker::FPSTracker()
{
	// Initialize FPS history to zero
	for (size_t i = 0; i < FPS_HISTORY_SIZE_; i++)
	{
		fps_history_[i] = {};
	}
}

void FPSTracker::Update(const sf::Time& delta_time)
{
	float delta_seconds = delta_time.asSeconds();

	// Ignore invalid samples
	if (delta_seconds <= 0.f)
		return;

	// Wrap around the index if needed
	if (current_index_ >= FPS_HISTORY_SIZE_)
		current_index_ = 0;

	// Store the FPS sample
	fps_history_[current_index_] = 1.f / delta_seconds;
	current_index_++;
}

void FPSTracker::UpdateStats(const sf::Time& delta_time)
{
	// Calculate average
	float count = 0.f;
	for (size_t i = 0; i < FPS_HISTORY_SIZE_; i++)
	{
		count += fps_history_[i];
	}
	current_average_fps_ = count / FPS_HISTORY_SIZE_;

	// Calculate highs and lows
	auto sorted = GetSortedHistory();
	current_highs_fps_ = sorted[FPS_HISTORY_SIZE_ - 1];
	current_lows_fps_ = sorted[0];

	// Current time per frame in ms
	current_frame_time_ms_ = delta_time.asMilliseconds();
	spdlog::info("FPS Stats Updated - Avg: {:.2f}, High: {:.2f}, Low: {:.2f}, Frame Time: {:.2f} ms",
		current_average_fps_, current_highs_fps_, current_lows_fps_, current_frame_time_ms_);
	spdlog::info("Current milliseconds per frame: {}", delta_time.asMilliseconds());
}

std::array<float, FPSTracker::FPS_HISTORY_SIZE_> FPSTracker::GetSortedHistory()
{
	std::array<float, FPS_HISTORY_SIZE_> sorted_history;
	std::copy(std::begin(fps_history_), std::end(fps_history_), sorted_history.begin());
	std::sort(sorted_history.begin(), sorted_history.end());
	return sorted_history;
}