// xstddef internal header (core)

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once
#ifndef _XSTDDEF_
#define _XSTDDEF_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <cstddef>
#include <cstdlib>
#include <initializer_list>
#include <xtr1common>

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
// TYPE DEFINITIONS
template <class>
// false value attached to a dependent name (for static_assert)
_INLINE_VAR constexpr bool _Always_false = false;

// FUNCTIONAL STUFF (from <functional>)
#if _HAS_AUTO_PTR_ETC
// STRUCT TEMPLATE unary_function
template <class _Arg, class _Result>
struct unary_function { // base class for unary functions
    using argument_type = _Arg;
    using result_type   = _Result;
};

// STRUCT TEMPLATE binary_function
template <class _Arg1, class _Arg2, class _Result>
struct binary_function { // base class for binary functions
    using first_argument_type  = _Arg1;
    using second_argument_type = _Arg2;
    using result_type          = _Result;
};
#endif // _HAS_AUTO_PTR_ETC

// STRUCT TEMPLATE plus
template <class _Ty = void>
struct plus {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _RESULT_TYPE_NAME;

    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left + _Right;
    }
};

// STRUCT TEMPLATE minus
template <class _Ty = void>
struct minus {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _RESULT_TYPE_NAME;

    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left - _Right;
    }
};

// STRUCT TEMPLATE multiplies
template <class _Ty = void>
struct multiplies {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _RESULT_TYPE_NAME;

    constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left * _Right;
    }
};

// STRUCT TEMPLATE equal_to
template <class _Ty = void>
struct equal_to {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left == _Right;
    }
};

// STRUCT TEMPLATE not_equal_to
template <class _Ty = void>
struct not_equal_to {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left != _Right;
    }
};

// STRUCT TEMPLATE greater
template <class _Ty = void>
struct greater {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left > _Right;
    }
};

// STRUCT TEMPLATE less
template <class _Ty = void>
struct less {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left < _Right;
    }
};

// STRUCT TEMPLATE greater_equal
template <class _Ty = void>
struct greater_equal {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left >= _Right;
    }
};

// STRUCT TEMPLATE less_equal
template <class _Ty = void>
struct less_equal {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left <= _Right;
    }
};

// STRUCT TEMPLATE SPECIALIZATION plus
template <>
struct plus<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        // ???? noexcept?? ?????? ???? ???? ?????? ????????. 
        // ?? ???? noexcept?? ?????? ???? expression?? ???? operator????. 
        // - ???? expression?? noexcept ?????? ???? ?? ???????? ?????? ????????. 
        // http://egloos.zum.com/sweeper/v/3148916

        // auto?? decltype?? ???? ???? ?????? ???? ????????. 
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION minus
template <>
struct minus<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION multiplies
template <>
struct multiplies<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION equal_to
template <>
struct equal_to<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION not_equal_to
template <>
struct not_equal_to<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION greater
template <>
struct greater<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION less
template <>
struct less<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION greater_equal
template <>
struct greater_equal<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// STRUCT TEMPLATE SPECIALIZATION less_equal
template <>
struct less_equal<void> {
    template <class _Ty1, class _Ty2>
    constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right))) // strengthened
        -> decltype(static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

// FUNCTION TEMPLATE addressof
template <class _Ty>
_NODISCARD constexpr _Ty* addressof(_Ty& _Val) noexcept {
    return __builtin_addressof(_Val);
}

template <class _Ty>
const _Ty* addressof(const _Ty&&) = delete;

// Fancy ???????? ????????? 
// An abstraction that acts like a pointer is a fancy pointer.
// ?????? iterator?? ????. 

// FUNCTION TEMPLATE _Unfancy
template <class _Ptrty>
_NODISCARD constexpr auto _Unfancy(_Ptrty _Ptr) noexcept { // converts from a fancy pointer to a plain pointer
    return _STD addressof(*_Ptr);
}

template <class _Ty>
_NODISCARD constexpr _Ty* _Unfancy(_Ty* _Ptr) noexcept { // do nothing for plain pointers
    return _Ptr;
}
_STD_END

#define _EMIT_CDECL(FUNC, OPT1, OPT2, OPT3) FUNC(__cdecl, OPT1, OPT2, OPT3)

#ifdef _M_CEE
#define _EMIT_CLRCALL(FUNC, OPT1, OPT2, OPT3) FUNC(__clrcall, OPT1, OPT2, OPT3)

#else // _M_CEE
#define _EMIT_CLRCALL(FUNC, OPT1, OPT2, OPT3)
#endif // _M_CEE

#if defined(_M_IX86) && !defined(_M_CEE)
#define _EMIT_FASTCALL(FUNC, OPT1, OPT2, OPT3) FUNC(__fastcall, OPT1, OPT2, OPT3)

#else // defined(_M_IX86) && !defined(_M_CEE)
#define _EMIT_FASTCALL(FUNC, OPT1, OPT2, OPT3)
#endif // defined(_M_IX86) && !defined(_M_CEE)

#ifdef _M_IX86
#define _EMIT_STDCALL(FUNC, OPT1, OPT2, OPT3)  FUNC(__stdcall, OPT1, OPT2, OPT3)
#define _EMIT_THISCALL(FUNC, OPT1, OPT2, OPT3) FUNC(__thiscall, OPT1, OPT2, OPT3)

#else // _M_IX86
#define _EMIT_STDCALL(FUNC, OPT1, OPT2, OPT3)
#define _EMIT_THISCALL(FUNC, OPT1, OPT2, OPT3)
#endif // _M_IX86

#if ((defined(_M_IX86) && _M_IX86_FP >= 2) || defined(_M_X64)) && !defined(_M_CEE)
#define _EMIT_VECTORCALL(FUNC, OPT1, OPT2, OPT3) FUNC(__vectorcall, OPT1, OPT2, OPT3)

#else // defined(_M_IX86) && _M_IX86_FP >= 2 etc.
#define _EMIT_VECTORCALL(FUNC, OPT1, OPT2, OPT3)
#endif // defined(_M_IX86) && _M_IX86_FP >= 2 etc.

#define _NON_MEMBER_CALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT) \
    _EMIT_CDECL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)          \
    _EMIT_CLRCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)        \
    _EMIT_FASTCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)       \
    _EMIT_STDCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)        \
    _EMIT_VECTORCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)

#define _NON_MEMBER_CALL_CV(FUNC, REF_OPT, NOEXCEPT_OPT)    \
    _NON_MEMBER_CALL(FUNC, , REF_OPT, NOEXCEPT_OPT)         \
    _NON_MEMBER_CALL(FUNC, const, REF_OPT, NOEXCEPT_OPT)    \
    _NON_MEMBER_CALL(FUNC, volatile, REF_OPT, NOEXCEPT_OPT) \
    _NON_MEMBER_CALL(FUNC, const volatile, REF_OPT, NOEXCEPT_OPT)

#define _NON_MEMBER_CALL_CV_REF(FUNC, NOEXCEPT_OPT) \
    _NON_MEMBER_CALL_CV(FUNC, , NOEXCEPT_OPT)       \
    _NON_MEMBER_CALL_CV(FUNC, &, NOEXCEPT_OPT)      \
    _NON_MEMBER_CALL_CV(FUNC, &&, NOEXCEPT_OPT)

#ifdef __cpp_noexcept_function_type
#define _NON_MEMBER_CALL_CV_REF_NOEXCEPT(FUNC) \
    _NON_MEMBER_CALL_CV_REF(FUNC, )            \
    _NON_MEMBER_CALL_CV_REF(FUNC, noexcept)
#else // __cpp_noexcept_function_type
#define _NON_MEMBER_CALL_CV_REF_NOEXCEPT(FUNC) _NON_MEMBER_CALL_CV_REF(FUNC, )
#endif // __cpp_noexcept_function_type

#define _MEMBER_CALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT) \
    _EMIT_CDECL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)      \
    _EMIT_CLRCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)    \
    _EMIT_FASTCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)   \
    _EMIT_STDCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)    \
    _EMIT_THISCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)   \
    _EMIT_VECTORCALL(FUNC, CV_OPT, REF_OPT, NOEXCEPT_OPT)

#define _MEMBER_CALL_CV(FUNC, REF_OPT, NOEXCEPT_OPT)    \
    _MEMBER_CALL(FUNC, , REF_OPT, NOEXCEPT_OPT)         \
    _MEMBER_CALL(FUNC, const, REF_OPT, NOEXCEPT_OPT)    \
    _MEMBER_CALL(FUNC, volatile, REF_OPT, NOEXCEPT_OPT) \
    _MEMBER_CALL(FUNC, const volatile, REF_OPT, NOEXCEPT_OPT)

#define _MEMBER_CALL_CV_REF(FUNC, NOEXCEPT_OPT) \
    _MEMBER_CALL_CV(FUNC, , NOEXCEPT_OPT)       \
    _MEMBER_CALL_CV(FUNC, &, NOEXCEPT_OPT)      \
    _MEMBER_CALL_CV(FUNC, &&, NOEXCEPT_OPT)

#ifdef __cpp_noexcept_function_type
#define _MEMBER_CALL_CV_REF_NOEXCEPT(FUNC) \
    _MEMBER_CALL_CV_REF(FUNC, )            \
    _MEMBER_CALL_CV_REF(FUNC, noexcept)
#else // __cpp_noexcept_function_type
#define _MEMBER_CALL_CV_REF_NOEXCEPT(FUNC) _MEMBER_CALL_CV_REF(FUNC, )
#endif // __cpp_noexcept_function_type

#define _CLASS_DEFINE_CONST(CLASS) \
    CLASS(_EMPTY_ARGUMENT)         \
    CLASS(const)

#ifdef __cpp_noexcept_function_type
#define _CLASS_DEFINE_CV_REF_NOEXCEPT(CLASS) \
    CLASS(_EMPTY_ARGUMENT)                   \
    CLASS(const)                             \
    CLASS(volatile)                          \
    CLASS(const volatile)                    \
    CLASS(&)                                 \
    CLASS(const&)                            \
    CLASS(volatile&)                         \
    CLASS(const volatile&)                   \
    CLASS(&&)                                \
    CLASS(const&&)                           \
    CLASS(volatile&&)                        \
    CLASS(const volatile&&)                  \
    CLASS(noexcept)                          \
    CLASS(const noexcept)                    \
    CLASS(volatile noexcept)                 \
    CLASS(const volatile noexcept)           \
    CLASS(&noexcept)                         \
    CLASS(const& noexcept)                   \
    CLASS(volatile& noexcept)                \
    CLASS(const volatile& noexcept)          \
    CLASS(&&noexcept)                        \
    CLASS(const&& noexcept)                  \
    CLASS(volatile&& noexcept)               \
    CLASS(const volatile&& noexcept)
#else // __cpp_noexcept_function_type
#define _CLASS_DEFINE_CV_REF_NOEXCEPT(CLASS) \
    CLASS(_EMPTY_ARGUMENT)                   \
    CLASS(const)                             \
    CLASS(volatile)                          \
    CLASS(const volatile)                    \
    CLASS(&)                                 \
    CLASS(const&)                            \
    CLASS(volatile&)                         \
    CLASS(const volatile&)                   \
    CLASS(&&)                                \
    CLASS(const&&)                           \
    CLASS(volatile&&)                        \
    CLASS(const volatile&&)
#endif // __cpp_noexcept_function_type

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif // _STL_COMPILER_PREPROCESSOR
#endif // _XSTDDEF_
