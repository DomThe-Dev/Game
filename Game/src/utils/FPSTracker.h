#pragma once
#include <SFML/System.hpp>
#include <array>

/// <summary>
/// Keeps track of FPS statistics over time. Call update to add samples, and update stats to recalculate averages, highs, and lows.
/// </summary>
class FPSTracker
{
public:
	FPSTracker();

	/// <summary>
	/// Adds an extra sample to the FPS history.
	/// </summary>
	/// <param name="delta_time"></param>
	void Update(const sf::Time& delta_time);
	/// <summary>
	/// Updates the current stats: average, highs, lows.
	/// </summary>
	void UpdateStats(const sf::Time& delta_time);

	/// <summary>
	/// Returns the last calculated average FPS.
	/// </summary>
	/// <returns>Current average FPS</returns>
	const float& GetAverageFps() const { return current_average_fps_; }
	/// <summary>
	/// Returns the last calculated Frame Time in MS.
	/// </summary>
	/// <returns>Current frame time in ms</returns>
	const float& GetFrameTimeMs() const { return current_frame_time_ms_; }
	/// <summary>
	/// Returns the last calculated High FPS.
	/// </summary>
	/// <returns>Current high in FPS history</returns>
	const float& GetHighsFps() const { return current_highs_fps_; }
	/// <summary>
	/// Returns the last calculated Low FPS.
	/// </summary>
	/// <returns>Current low in FPS history</returns>
	const float& GetLowsFps() const { return current_lows_fps_; }
private:
	static constexpr size_t FPS_HISTORY_SIZE_ = 64; // Must be a power of 2 for performance. Constexpr to make it a compile time constant, making it faster
	float fps_history_[FPS_HISTORY_SIZE_];
	float current_average_fps_ = 0.f;
	float current_highs_fps_ = 0.f;
	float current_lows_fps_ = 0.f;
	float current_frame_time_ms_ = 0.f;

	size_t current_index_ = 0; // Used for going through the FPS hisroty in a circular manner

	/// <summary>
	/// Sorts the FPS history and returns a copy of it.
	/// </summary>
	/// <returns>Sorted FPS History</returns>
	std::array<float, FPS_HISTORY_SIZE_> GetSortedHistory();
};

