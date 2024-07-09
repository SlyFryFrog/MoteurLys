#pragma once

#include <map>
#include <functional>

namespace LilyPad
{
    class Key
    {
    public:
		explicit Key(const std::map<int, std::function<void()>> &assigned_keys) : assigned_keys(assigned_keys) {}

    	void key_callback();

    	void assign_key(int keyID, std::function<void()> handler);

    private:
    	std::map<int, std::function<void()>> assigned_keys;
    };
} // namespace LilyPad
