#pragma once

#include <cstddef>

class Util
{
public:
    Util() = delete;

public:
    static constexpr size_t HIGHEST_BIT_MASK = static_cast<size_t>(1) << (sizeof(size_t) * CHAR_BIT - 1);

public:
    
    inline static size_t UpAlignment(size_t size, size_t alignment)
    {
        return (size + alignment - 1) & ~(alignment - 1);
    }

    template <typename T>
    inline static size_t GetPaddedSize(size_t alignment)
    {
        return Util::UpAlignment(sizeof(T), alignment);
    }

    inline static size_t UpAlignmentPowerOfTwo(size_t value)
    {
        if (value <= 4)
            return 4;

        value--;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;
        if constexpr (sizeof(size_t) > 4)
            value |= value >> 32;

        return value + 1;
    }
};