template<typename ENUM>
struct is_bitmask_enum : std::false_type /* By default, no enum is a bitmask enum */
{
};


template<typename ENUM>
inline bool is_flag_on(ENUM e, ENUM bit)
{
    using under = typename std::underlying_type<ENUM>::type;
    return static_cast<under>(e & bit) != 0;
}

constexpr std::size_t bitmask(unsigned int shift)
{
    return 1u << shift;
}


///OR operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator| (ENUM lhs, ENUM rhs)
{
    using under = typename std::underlying_type<ENUM>::type;
    return static_cast<ENUM>(static_cast<under>(lhs) | static_cast<under>(rhs));
}

///AND operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator& (ENUM lhs, ENUM rhs)
{
    using under = typename std::underlying_type<ENUM>::type;
    return static_cast<ENUM>(static_cast<under>(lhs) & static_cast<under>(rhs));
}

///XOR operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator^ (ENUM lhs, ENUM rhs)
{
    using under = typename std::underlying_type<ENUM>::type;
    return static_cast<ENUM>(static_cast<under>(lhs) ^ static_cast<under>(rhs));
}

///NOT operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator~ (ENUM rhs)
{
    using under = typename std::underlying_type<ENUM>::type;
    return static_cast<ENUM>(~static_cast<under>(rhs));
}


///OR assignment operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator|= (ENUM & lhs, ENUM rhs)
{
    return lhs = lhs | rhs;
}

///AND assignment operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator&= (ENUM & lhs, ENUM rhs)
{
    return lhs = lhs & rhs;
}

///XOR assignment operator
template<typename ENUM>
inline typename std::enable_if<is_bitmask_enum<ENUM>::value, ENUM>::type operator^= (ENUM & lhs, ENUM rhs)
{
    return lhs = lhs ^ rhs;
}
