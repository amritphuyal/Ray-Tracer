#include "HandmadeMath.h"
COVERAGE(HMM_SinF, 1)
HMM_INLINE float HMM_SinF(float Radians)
{
    ASSERT_COVERED(HMM_SinF);

    float Result = HMM_SINF(Radians);

    return (Result);
}

COVERAGE(HMM_CosF, 1)
HMM_INLINE float HMM_CosF(float Radians)
{
    ASSERT_COVERED(HMM_CosF);

    float Result = HMM_COSF(Radians);

    return (Result);
}

COVERAGE(HMM_TanF, 1)
HMM_INLINE float HMM_TanF(float Radians)
{
    ASSERT_COVERED(HMM_TanF);

    float Result = HMM_TANF(Radians);

    return (Result);
}

COVERAGE(HMM_ACosF, 1)
HMM_INLINE float HMM_ACosF(float Radians)
{
    ASSERT_COVERED(HMM_ACosF);

    float Result = HMM_ACOSF(Radians);

    return (Result);
}

COVERAGE(HMM_ATanF, 1)
HMM_INLINE float HMM_ATanF(float Radians)
{
    ASSERT_COVERED(HMM_ATanF);

    float Result = HMM_ATANF(Radians);

    return (Result);
}

COVERAGE(HMM_ATan2F, 1)
HMM_INLINE float HMM_ATan2F(float Left, float Right)
{
    ASSERT_COVERED(HMM_ATan2F);

    float Result = HMM_ATAN2F(Left, Right);

    return (Result);
}

COVERAGE(HMM_ExpF, 1)
HMM_INLINE float HMM_ExpF(float Float)
{
    ASSERT_COVERED(HMM_ExpF);

    float Result = HMM_EXPF(Float);

    return (Result);
}

COVERAGE(HMM_LogF, 1)
HMM_INLINE float HMM_LogF(float Float)
{
    ASSERT_COVERED(HMM_LogF);

    float Result = HMM_LOGF(Float);

    return (Result);
}

COVERAGE(HMM_SquareRootF, 1)
HMM_INLINE float HMM_SquareRootF(float Float)
{
    ASSERT_COVERED(HMM_SquareRootF);

    float Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 In = _mm_set_ss(Float);
    __m128 Out = _mm_sqrt_ss(In);
    Result = _mm_cvtss_f32(Out);
#else
    Result = HMM_SQRTF(Float);
#endif

    return(Result);
}

COVERAGE(HMM_RSquareRootF, 1)
HMM_INLINE float HMM_RSquareRootF(float Float)
{
    ASSERT_COVERED(HMM_RSquareRootF);

    float Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 In = _mm_set_ss(Float);
    __m128 Out = _mm_rsqrt_ss(In);
    Result = _mm_cvtss_f32(Out);
#else
    Result = 1.0f/HMM_SquareRootF(Float);
#endif

    return(Result);
}

HMM_EXTERN float HMM_Power(float Base, int Exponent);

COVERAGE(HMM_PowerF, 1)
HMM_INLINE float HMM_PowerF(float Base, float Exponent)
{
    ASSERT_COVERED(HMM_PowerF);

    float Result = HMM_EXPF(Exponent * HMM_LOGF(Base));

    return (Result);
}


/*
 * Utility functions
 */

COVERAGE(HMM_ToRadians, 1)
HMM_INLINE float HMM_ToRadians(float Degrees)
{
    ASSERT_COVERED(HMM_ToRadians);

    float Result = Degrees * (HMM_PI32 / 180.0f);

    return (Result);
}

COVERAGE(HMM_Lerp, 1)
HMM_INLINE float HMM_Lerp(float A, float Time, float B)
{
    ASSERT_COVERED(HMM_Lerp);

    float Result = (1.0f - Time) * A + Time * B;

    return (Result);
}

COVERAGE(HMM_Clamp, 1)
HMM_INLINE float HMM_Clamp(float Min, float Value, float Max)
{
    ASSERT_COVERED(HMM_Clamp);

    float Result = Value;

    if(Result < Min)
    {
        Result = Min;
    }
    else if(Result > Max)
    {
        Result = Max;
    }

    return (Result);
}


/*
 * Vector initialization
 */

COVERAGE(HMM_Vec2, 1)
HMM_INLINE hmm_vec2 HMM_Vec2(float X, float Y)
{
    ASSERT_COVERED(HMM_Vec2);

    hmm_vec2 Result;

    Result.X = X;
    Result.Y = Y;

    return (Result);
}

COVERAGE(HMM_Vec2i, 1)
HMM_INLINE hmm_vec2 HMM_Vec2i(int X, int Y)
{
    ASSERT_COVERED(HMM_Vec2i);

    hmm_vec2 Result;

    Result.X = (float)X;
    Result.Y = (float)Y;

    return (Result);
}

COVERAGE(HMM_Vec3, 1)
HMM_INLINE hmm_vec3 HMM_Vec3(float X, float Y, float Z)
{
    ASSERT_COVERED(HMM_Vec3);

    hmm_vec3 Result;

    Result.X = X;
    Result.Y = Y;
    Result.Z = Z;

    return (Result);
}

COVERAGE(HMM_Vec3i, 1)
HMM_INLINE hmm_vec3 HMM_Vec3i(int X, int Y, int Z)
{
    ASSERT_COVERED(HMM_Vec3i);

    hmm_vec3 Result;

    Result.X = (float)X;
    Result.Y = (float)Y;
    Result.Z = (float)Z;

    return (Result);
}

COVERAGE(HMM_Vec4, 1)
HMM_INLINE hmm_vec4 HMM_Vec4(float X, float Y, float Z, float W)
{
    ASSERT_COVERED(HMM_Vec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_setr_ps(X, Y, Z, W);
#else
    Result.X = X;
    Result.Y = Y;
    Result.Z = Z;
    Result.W = W;
#endif

    return (Result);
}

COVERAGE(HMM_Vec4i, 1)
HMM_INLINE hmm_vec4 HMM_Vec4i(int X, int Y, int Z, int W)
{
    ASSERT_COVERED(HMM_Vec4i);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_setr_ps((float)X, (float)Y, (float)Z, (float)W);
#else
    Result.X = (float)X;
    Result.Y = (float)Y;
    Result.Z = (float)Z;
    Result.W = (float)W;
#endif

    return (Result);
}

COVERAGE(HMM_Vec4v, 1)
HMM_INLINE hmm_vec4 HMM_Vec4v(const hmm_vec3& Vector, float W)
{
    ASSERT_COVERED(HMM_Vec4v);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_setr_ps(Vector.X, Vector.Y, Vector.Z, W);
#else
    Result.XYZ = Vector;
    Result.W = W;
#endif

    return (Result);
}


/*
 * Binary vector operations
 */
COVERAGE(HMM_AddVec2, 1)
HMM_INLINE hmm_vec2 HMM_AddVec2(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_AddVec2);

    hmm_vec2 Result;

    Result.X = Left.X + Right.X;
    Result.Y = Left.Y + Right.Y;

    return (Result);
}

COVERAGE(HMM_AddVec3, 1)
HMM_INLINE hmm_vec3 HMM_AddVec3(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_AddVec3);

    hmm_vec3 Result;

    Result.X = Left.X + Right.X;
    Result.Y = Left.Y + Right.Y;
    Result.Z = Left.Z + Right.Z;

    return (Result);
}

COVERAGE(HMM_AddVec4, 1)
HMM_INLINE hmm_vec4 HMM_AddVec4(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_AddVec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_add_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else
    Result.X = Left.X + Right.X;
    Result.Y = Left.Y + Right.Y;
    Result.Z = Left.Z + Right.Z;
    Result.W = Left.W + Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_SubtractVec2, 1)
HMM_INLINE hmm_vec2 HMM_SubtractVec2(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_SubtractVec2);

    hmm_vec2 Result;

    Result.X = Left.X - Right.X;
    Result.Y = Left.Y - Right.Y;

    return (Result);
}

COVERAGE(HMM_SubtractVec3, 1)
HMM_INLINE hmm_vec3 HMM_SubtractVec3(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_SubtractVec3);

    hmm_vec3 Result;

    Result.X = Left.X - Right.X;
    Result.Y = Left.Y - Right.Y;
    Result.Z = Left.Z - Right.Z;

    return (Result);
}

COVERAGE(HMM_SubtractVec4, 1)
HMM_INLINE hmm_vec4 HMM_SubtractVec4(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_SubtractVec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_sub_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else
    Result.X = Left.X - Right.X;
    Result.Y = Left.Y - Right.Y;
    Result.Z = Left.Z - Right.Z;
    Result.W = Left.W - Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_MultiplyVec2, 1)
HMM_INLINE hmm_vec2 HMM_MultiplyVec2(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2);

    hmm_vec2 Result;

    Result.X = Left.X * Right.X;
    Result.Y = Left.Y * Right.Y;

    return (Result);
}

COVERAGE(HMM_MultiplyVec2f, 1)
HMM_INLINE hmm_vec2 HMM_MultiplyVec2f(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2f);

    hmm_vec2 Result;

    Result.X = Left.X * Right;
    Result.Y = Left.Y * Right;

    return (Result);
}

COVERAGE(HMM_MultiplyVec3, 1)
HMM_INLINE hmm_vec3 HMM_MultiplyVec3(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3);

    hmm_vec3 Result;

    Result.X = Left.X * Right.X;
    Result.Y = Left.Y * Right.Y;
    Result.Z = Left.Z * Right.Z;

    return (Result);
}

COVERAGE(HMM_MultiplyVec3f, 1)
HMM_INLINE hmm_vec3 HMM_MultiplyVec3f(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3f);

    hmm_vec3 Result;

    Result.X = Left.X * Right;
    Result.Y = Left.Y * Right;
    Result.Z = Left.Z * Right;

    return (Result);
}

COVERAGE(HMM_MultiplyVec4, 1)
HMM_INLINE hmm_vec4 HMM_MultiplyVec4(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_mul_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else
    Result.X = Left.X * Right.X;
    Result.Y = Left.Y * Right.Y;
    Result.Z = Left.Z * Right.Z;
    Result.W = Left.W * Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_MultiplyVec4f, 1)
HMM_INLINE hmm_vec4 HMM_MultiplyVec4f(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4f);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Right);
    Result.InternalElementsSSE = _mm_mul_ps(Left.InternalElementsSSE, Scalar);
#else
    Result.X = Left.X * Right;
    Result.Y = Left.Y * Right;
    Result.Z = Left.Z * Right;
    Result.W = Left.W * Right;
#endif

    return (Result);
}

COVERAGE(HMM_DivideVec2, 1)
HMM_INLINE hmm_vec2 HMM_DivideVec2(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_DivideVec2);

    hmm_vec2 Result;

    Result.X = Left.X / Right.X;
    Result.Y = Left.Y / Right.Y;

    return (Result);
}

COVERAGE(HMM_DivideVec2f, 1)
HMM_INLINE hmm_vec2 HMM_DivideVec2f(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec2f);

    hmm_vec2 Result;

    Result.X = Left.X / Right;
    Result.Y = Left.Y / Right;

    return (Result);
}

COVERAGE(HMM_DivideVec3, 1)
HMM_INLINE hmm_vec3 HMM_DivideVec3(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_DivideVec3);

    hmm_vec3 Result;

    Result.X = Left.X / Right.X;
    Result.Y = Left.Y / Right.Y;
    Result.Z = Left.Z / Right.Z;

    return (Result);
}

COVERAGE(HMM_DivideVec3f, 1)
HMM_INLINE hmm_vec3 HMM_DivideVec3f(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec3f);

    hmm_vec3 Result;

    Result.X = Left.X / Right;
    Result.Y = Left.Y / Right;
    Result.Z = Left.Z / Right;

    return (Result);
}

COVERAGE(HMM_DivideVec4, 1)
HMM_INLINE hmm_vec4 HMM_DivideVec4(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_DivideVec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_div_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else
    Result.X = Left.X / Right.X;
    Result.Y = Left.Y / Right.Y;
    Result.Z = Left.Z / Right.Z;
    Result.W = Left.W / Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_DivideVec4f, 1)
HMM_INLINE hmm_vec4 HMM_DivideVec4f(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec4f);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Right);
    Result.InternalElementsSSE = _mm_div_ps(Left.InternalElementsSSE, Scalar);
#else
    Result.X = Left.X / Right;
    Result.Y = Left.Y / Right;
    Result.Z = Left.Z / Right;
    Result.W = Left.W / Right;
#endif

    return (Result);
}

COVERAGE(HMM_EqualsVec2, 1)
HMM_INLINE hmm_bool HMM_EqualsVec2(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_EqualsVec2);

    hmm_bool Result = (Left.X == Right.X && Left.Y == Right.Y);

    return (Result);
}

COVERAGE(HMM_EqualsVec3, 1)
HMM_INLINE hmm_bool HMM_EqualsVec3(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_EqualsVec3);

    hmm_bool Result = (Left.X == Right.X && Left.Y == Right.Y && Left.Z == Right.Z);

    return (Result);
}

COVERAGE(HMM_EqualsVec4, 1)
HMM_INLINE hmm_bool HMM_EqualsVec4(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_EqualsVec4);

    hmm_bool Result = (Left.X == Right.X && Left.Y == Right.Y && Left.Z == Right.Z && Left.W == Right.W);

    return (Result);
}

COVERAGE(HMM_DotVec2, 1)
HMM_INLINE float HMM_DotVec2(hmm_vec2 VecOne, hmm_vec2 VecTwo)
{
    ASSERT_COVERED(HMM_DotVec2);

    float Result = (VecOne.X * VecTwo.X) + (VecOne.Y * VecTwo.Y);

    return (Result);
}

COVERAGE(HMM_DotVec3, 1)
HMM_INLINE float HMM_DotVec3(const hmm_vec3& VecOne,const hmm_vec3& VecTwo)
{
    ASSERT_COVERED(HMM_DotVec3);

    float Result = (VecOne.X * VecTwo.X) + (VecOne.Y * VecTwo.Y) + (VecOne.Z * VecTwo.Z);

    return (Result);
}

COVERAGE(HMM_DotVec4, 1)
HMM_INLINE float HMM_DotVec4(hmm_vec4 VecOne, hmm_vec4 VecTwo)
{
    ASSERT_COVERED(HMM_DotVec4);

    float Result;

    // NOTE(zak): IN the future if we wanna check what version SSE is support
    // we can use _mm_dp_ps (4.3) but for now we will use the old way.
    // Or a r = _mm_mul_ps(v1, v2), r = _mm_hadd_ps(r, r), r = _mm_hadd_ps(r, r) for SSE3
#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_mul_ps(VecOne.InternalElementsSSE, VecTwo.InternalElementsSSE);
    __m128 SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(0, 1, 2, 3));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    _mm_store_ss(&Result, SSEResultOne);
#else
    Result = (VecOne.X * VecTwo.X) + (VecOne.Y * VecTwo.Y) + (VecOne.Z * VecTwo.Z) + (VecOne.W * VecTwo.W);
#endif

    return (Result);
}

COVERAGE(HMM_Cross, 1)
HMM_INLINE hmm_vec3 HMM_Cross(const hmm_vec3& VecOne,const hmm_vec3& VecTwo)
{
    ASSERT_COVERED(HMM_Cross);

    hmm_vec3 Result;

    Result.X = (VecOne.Y * VecTwo.Z) - (VecOne.Z * VecTwo.Y);
    Result.Y = (VecOne.Z * VecTwo.X) - (VecOne.X * VecTwo.Z);
    Result.Z = (VecOne.X * VecTwo.Y) - (VecOne.Y * VecTwo.X);

    return (Result);
}


/*
 * Unary vector operations
 */

COVERAGE(HMM_LengthSquaredVec2, 1)
HMM_INLINE float HMM_LengthSquaredVec2(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec2);

    float Result = HMM_DotVec2(A, A);

    return (Result);
}

COVERAGE(HMM_LengthSquaredVec3, 1)
HMM_INLINE float HMM_LengthSquaredVec3(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec3);

    float Result = HMM_DotVec3(A, A);

    return (Result);
}

COVERAGE(HMM_LengthSquaredVec4, 1)
HMM_INLINE float HMM_LengthSquaredVec4(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec4);

    float Result = HMM_DotVec4(A, A);

    return (Result);
}

COVERAGE(HMM_LengthVec2, 1)
HMM_INLINE float HMM_LengthVec2(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_LengthVec2);

    float Result = HMM_SquareRootF(HMM_LengthSquaredVec2(A));

    return (Result);
}

COVERAGE(HMM_LengthVec3, 1)
HMM_INLINE float HMM_LengthVec3(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_LengthVec3);

    float Result = HMM_SquareRootF(HMM_LengthSquaredVec3(A));

    return (Result);
}

COVERAGE(HMM_LengthVec4, 1)
HMM_INLINE float HMM_LengthVec4(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_LengthVec4);

    float Result = HMM_SquareRootF(HMM_LengthSquaredVec4(A));

    return(Result);
}

COVERAGE(HMM_NormalizeVec2, 2)
HMM_INLINE hmm_vec2 HMM_NormalizeVec2(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_NormalizeVec2);

    hmm_vec2 Result = {0};

    float VectorLength = HMM_LengthVec2(A);

    /* NOTE(kiljacken): We need a zero check to not divide-by-zero */
    if (VectorLength != 0.0f)
    {
        ASSERT_COVERED(HMM_NormalizeVec2);

        Result.X = A.X * (1.0f / VectorLength);
        Result.Y = A.Y * (1.0f / VectorLength);
    }

    return (Result);
}

COVERAGE(HMM_NormalizeVec3, 2)
HMM_INLINE hmm_vec3 HMM_NormalizeVec3(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_NormalizeVec3);

    hmm_vec3 Result = {0};

    float VectorLength = HMM_LengthVec3(A);

    /* NOTE(kiljacken): We need a zero check to not divide-by-zero */
    if (VectorLength != 0.0f)
    {
        ASSERT_COVERED(HMM_NormalizeVec3);

        Result.X = A.X * (1.0f / VectorLength);
        Result.Y = A.Y * (1.0f / VectorLength);
        Result.Z = A.Z * (1.0f / VectorLength);
    }

    return (Result);
}

COVERAGE(HMM_NormalizeVec4, 2)
HMM_INLINE hmm_vec4 HMM_NormalizeVec4(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_NormalizeVec4);

    hmm_vec4 Result = {0};

    float VectorLength = HMM_LengthVec4(A);

    /* NOTE(kiljacken): We need a zero check to not divide-by-zero */
    if (VectorLength != 0.0f)
    {
        ASSERT_COVERED(HMM_NormalizeVec4);

        float Multiplier = 1.0f / VectorLength;

#ifdef HANDMADE_MATH__USE_SSE
        __m128 SSEMultiplier = _mm_set1_ps(Multiplier);
        Result.InternalElementsSSE = _mm_mul_ps(A.InternalElementsSSE, SSEMultiplier);
#else
        Result.X = A.X * Multiplier;
        Result.Y = A.Y * Multiplier;
        Result.Z = A.Z * Multiplier;
        Result.W = A.W * Multiplier;
#endif
    }

    return (Result);
}

COVERAGE(HMM_FastNormalizeVec2, 1)
HMM_INLINE hmm_vec2 HMM_FastNormalizeVec2(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec2);

    return HMM_MultiplyVec2f(A, HMM_RSquareRootF(HMM_DotVec2(A, A)));
}

COVERAGE(HMM_FastNormalizeVec3, 1)
HMM_INLINE hmm_vec3 HMM_FastNormalizeVec3(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec3);

    return HMM_MultiplyVec3f(A, HMM_RSquareRootF(HMM_DotVec3(A, A)));
}

COVERAGE(HMM_FastNormalizeVec4, 1)
HMM_INLINE hmm_vec4 HMM_FastNormalizeVec4(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec4);

    return HMM_MultiplyVec4f(A, HMM_RSquareRootF(HMM_DotVec4(A, A)));
}


/*
 * SSE stuff
 */

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_LinearCombineSSE, 1)
HMM_INLINE __m128 HMM_LinearCombineSSE(__m128 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_LinearCombineSSE);

    __m128 Result;
    Result = _mm_mul_ps(_mm_shuffle_ps(Left, Left, 0x00), Right.Columns[0]);
    Result = _mm_add_ps(Result, _mm_mul_ps(_mm_shuffle_ps(Left, Left, 0x55), Right.Columns[1]));
    Result = _mm_add_ps(Result, _mm_mul_ps(_mm_shuffle_ps(Left, Left, 0xaa), Right.Columns[2]));
    Result = _mm_add_ps(Result, _mm_mul_ps(_mm_shuffle_ps(Left, Left, 0xff), Right.Columns[3]));

    return (Result);
}
#endif


/*
 * Matrix functions
 */

COVERAGE(HMM_Mat4, 1)
HMM_INLINE hmm_mat4 HMM_Mat4(void)
{
    ASSERT_COVERED(HMM_Mat4);

    hmm_mat4 Result = {0};

    return (Result);
}

COVERAGE(HMM_Mat4d, 1)
HMM_INLINE hmm_mat4 HMM_Mat4d(float Diagonal)
{
    ASSERT_COVERED(HMM_Mat4d);

    hmm_mat4 Result = HMM_Mat4();

    Result.Elements[0][0] = Diagonal;
    Result.Elements[1][1] = Diagonal;
    Result.Elements[2][2] = Diagonal;
    Result.Elements[3][3] = Diagonal;

    return (Result);
}

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_Transpose, 1)
HMM_INLINE hmm_mat4 HMM_Transpose(hmm_mat4 Matrix)
{
    ASSERT_COVERED(HMM_Transpose);

    hmm_mat4 Result = Matrix;

    _MM_TRANSPOSE4_PS(Result.Columns[0], Result.Columns[1], Result.Columns[2], Result.Columns[3]);

    return (Result);
}
#else
HMM_EXTERN hmm_mat4 HMM_Transpose(hmm_mat4 Matrix);
#endif

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_AddMat4, 1)
HMM_INLINE hmm_mat4 HMM_AddMat4(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_AddMat4);

    hmm_mat4 Result;

    Result.Columns[0] = _mm_add_ps(Left.Columns[0], Right.Columns[0]);
    Result.Columns[1] = _mm_add_ps(Left.Columns[1], Right.Columns[1]);
    Result.Columns[2] = _mm_add_ps(Left.Columns[2], Right.Columns[2]);
    Result.Columns[3] = _mm_add_ps(Left.Columns[3], Right.Columns[3]);

    return (Result);
}
#else
HMM_EXTERN hmm_mat4 HMM_AddMat4(hmm_mat4 Left, hmm_mat4 Right);
#endif

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_SubtractMat4, 1)
HMM_INLINE hmm_mat4 HMM_SubtractMat4(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_SubtractMat4);

    hmm_mat4 Result;

    Result.Columns[0] = _mm_sub_ps(Left.Columns[0], Right.Columns[0]);
    Result.Columns[1] = _mm_sub_ps(Left.Columns[1], Right.Columns[1]);
    Result.Columns[2] = _mm_sub_ps(Left.Columns[2], Right.Columns[2]);
    Result.Columns[3] = _mm_sub_ps(Left.Columns[3], Right.Columns[3]);

    return (Result);
}
#else
HMM_EXTERN hmm_mat4 HMM_SubtractMat4(hmm_mat4 Left, hmm_mat4 Right);
#endif

HMM_EXTERN hmm_mat4 HMM_MultiplyMat4(hmm_mat4 Left, hmm_mat4 Right);

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_MultiplyMat4f, 1)
HMM_INLINE hmm_mat4 HMM_MultiplyMat4f(hmm_mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(HMM_MultiplyMat4f);

    hmm_mat4 Result;

    __m128 SSEScalar = _mm_set1_ps(Scalar);
    Result.Columns[0] = _mm_mul_ps(Matrix.Columns[0], SSEScalar);
    Result.Columns[1] = _mm_mul_ps(Matrix.Columns[1], SSEScalar);
    Result.Columns[2] = _mm_mul_ps(Matrix.Columns[2], SSEScalar);
    Result.Columns[3] = _mm_mul_ps(Matrix.Columns[3], SSEScalar);

    return (Result);
}
#else
HMM_EXTERN hmm_mat4 HMM_MultiplyMat4f(hmm_mat4 Matrix, float Scalar);
#endif

HMM_EXTERN hmm_vec4 HMM_MultiplyMat4ByVec4(hmm_mat4 Matrix, hmm_vec4 Vector);

#ifdef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_DivideMat4f, 1)
HMM_INLINE hmm_mat4 HMM_DivideMat4f(hmm_mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(HMM_DivideMat4f);

    hmm_mat4 Result;

    __m128 SSEScalar = _mm_set1_ps(Scalar);
    Result.Columns[0] = _mm_div_ps(Matrix.Columns[0], SSEScalar);
    Result.Columns[1] = _mm_div_ps(Matrix.Columns[1], SSEScalar);
    Result.Columns[2] = _mm_div_ps(Matrix.Columns[2], SSEScalar);
    Result.Columns[3] = _mm_div_ps(Matrix.Columns[3], SSEScalar);

    return (Result);
}
#else
HMM_EXTERN hmm_mat4 HMM_DivideMat4f(hmm_mat4 Matrix, float Scalar);
#endif


/*
 * Common graphics transformations
 */

COVERAGE(HMM_Orthographic, 1)
HMM_INLINE hmm_mat4 HMM_Orthographic(float Left, float Right, float Bottom, float Top, float Near, float Far)
{
    ASSERT_COVERED(HMM_Orthographic);

    hmm_mat4 Result = HMM_Mat4();

    Result.Elements[0][0] = 2.0f / (Right - Left);
    Result.Elements[1][1] = 2.0f / (Top - Bottom);
    Result.Elements[2][2] = 2.0f / (Near - Far);
    Result.Elements[3][3] = 1.0f;

    Result.Elements[3][0] = (Left + Right) / (Left - Right);
    Result.Elements[3][1] = (Bottom + Top) / (Bottom - Top);
    Result.Elements[3][2] = (Far + Near) / (Near - Far);

    return (Result);
}

COVERAGE(HMM_Perspective, 1)
HMM_INLINE hmm_mat4 HMM_Perspective(float FOV, float AspectRatio, float Near, float Far)
{
    ASSERT_COVERED(HMM_Perspective);

    hmm_mat4 Result = HMM_Mat4();

    // See https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluPerspective.xml

    float Cotangent = 1.0f / HMM_TanF(FOV * (HMM_PI32 / 360.0f));

    Result.Elements[0][0] = Cotangent / AspectRatio;
    Result.Elements[1][1] = Cotangent;
    Result.Elements[2][3] = -1.0f;
    Result.Elements[2][2] = (Near + Far) / (Near - Far);
    Result.Elements[3][2] = (2.0f * Near * Far) / (Near - Far);
    Result.Elements[3][3] = 0.0f;

    return (Result);
}

COVERAGE(HMM_Translate, 1)
HMM_INLINE hmm_mat4 HMM_Translate(const hmm_vec3& Translation)
{
    ASSERT_COVERED(HMM_Translate);

    hmm_mat4 Result = HMM_Mat4d(1.0f);

    Result.Elements[3][0] = Translation.X;
    Result.Elements[3][1] = Translation.Y;
    Result.Elements[3][2] = Translation.Z;

    return (Result);
}

HMM_EXTERN hmm_mat4 HMM_Rotate(float Angle,const hmm_vec3& Axis);

COVERAGE(HMM_Scale, 1)
HMM_INLINE hmm_mat4 HMM_Scale(const hmm_vec3& Scale)
{
    ASSERT_COVERED(HMM_Scale);

    hmm_mat4 Result = HMM_Mat4d(1.0f);

    Result.Elements[0][0] = Scale.X;
    Result.Elements[1][1] = Scale.Y;
    Result.Elements[2][2] = Scale.Z;

    return (Result);
}

HMM_EXTERN hmm_mat4 HMM_LookAt(const hmm_vec3& Eye,const hmm_vec3& Center,const hmm_vec3& Up);


/*
 * Quaternion operations
 */

COVERAGE(HMM_Quaternion, 1)
HMM_INLINE hmm_quaternion HMM_Quaternion(float X, float Y, float Z, float W)
{
    ASSERT_COVERED(HMM_Quaternion);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_setr_ps(X, Y, Z, W);
#else
    Result.X = X;
    Result.Y = Y;
    Result.Z = Z;
    Result.W = W;
#endif

    return (Result);
}

COVERAGE(HMM_QuaternionV4, 1)
HMM_INLINE hmm_quaternion HMM_QuaternionV4(hmm_vec4 Vector)
{
    ASSERT_COVERED(HMM_QuaternionV4);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = Vector.InternalElementsSSE;
#else
    Result.X = Vector.X;
    Result.Y = Vector.Y;
    Result.Z = Vector.Z;
    Result.W = Vector.W;
#endif

    return (Result);
}

COVERAGE(HMM_AddQuaternion, 1)
HMM_INLINE hmm_quaternion HMM_AddQuaternion(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_AddQuaternion);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_add_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else

    Result.X = Left.X + Right.X;
    Result.Y = Left.Y + Right.Y;
    Result.Z = Left.Z + Right.Z;
    Result.W = Left.W + Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_SubtractQuaternion, 1)
HMM_INLINE hmm_quaternion HMM_SubtractQuaternion(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_SubtractQuaternion);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.InternalElementsSSE = _mm_sub_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
#else

    Result.X = Left.X - Right.X;
    Result.Y = Left.Y - Right.Y;
    Result.Z = Left.Z - Right.Z;
    Result.W = Left.W - Right.W;
#endif

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternion, 1)
HMM_INLINE hmm_quaternion HMM_MultiplyQuaternion(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternion);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(Left.InternalElementsSSE, Left.InternalElementsSSE, _MM_SHUFFLE(0, 0, 0, 0)), _mm_setr_ps(0.f, -0.f, 0.f, -0.f));
    __m128 SSEResultTwo = _mm_shuffle_ps(Right.InternalElementsSSE, Right.InternalElementsSSE, _MM_SHUFFLE(0, 1, 2, 3));
    __m128 SSEResultThree = _mm_mul_ps(SSEResultTwo, SSEResultOne);

    SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(Left.InternalElementsSSE, Left.InternalElementsSSE, _MM_SHUFFLE(1, 1, 1, 1)) , _mm_setr_ps(0.f, 0.f, -0.f, -0.f));
    SSEResultTwo = _mm_shuffle_ps(Right.InternalElementsSSE, Right.InternalElementsSSE, _MM_SHUFFLE(1, 0, 3, 2));
    SSEResultThree = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));

    SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(Left.InternalElementsSSE, Left.InternalElementsSSE, _MM_SHUFFLE(2, 2, 2, 2)), _mm_setr_ps(-0.f, 0.f, 0.f, -0.f));
    SSEResultTwo = _mm_shuffle_ps(Right.InternalElementsSSE, Right.InternalElementsSSE, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultThree = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));

    SSEResultOne = _mm_shuffle_ps(Left.InternalElementsSSE, Left.InternalElementsSSE, _MM_SHUFFLE(3, 3, 3, 3));
    SSEResultTwo = _mm_shuffle_ps(Right.InternalElementsSSE, Right.InternalElementsSSE, _MM_SHUFFLE(3, 2, 1, 0));
    Result.InternalElementsSSE = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));
#else
    Result.X = (Left.X * Right.W) + (Left.Y * Right.Z) - (Left.Z * Right.Y) + (Left.W * Right.X);
    Result.Y = (-Left.X * Right.Z) + (Left.Y * Right.W) + (Left.Z * Right.X) + (Left.W * Right.Y);
    Result.Z = (Left.X * Right.Y) - (Left.Y * Right.X) + (Left.Z * Right.W) + (Left.W * Right.Z);
    Result.W = (-Left.X * Right.X) - (Left.Y * Right.Y) - (Left.Z * Right.Z) + (Left.W * Right.W);
#endif

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionF, 1)
HMM_INLINE hmm_quaternion HMM_MultiplyQuaternionF(hmm_quaternion Left, float Multiplicative)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionF);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Multiplicative);
    Result.InternalElementsSSE = _mm_mul_ps(Left.InternalElementsSSE, Scalar);
#else
    Result.X = Left.X * Multiplicative;
    Result.Y = Left.Y * Multiplicative;
    Result.Z = Left.Z * Multiplicative;
    Result.W = Left.W * Multiplicative;
#endif

    return (Result);
}

COVERAGE(HMM_DivideQuaternionF, 1)
HMM_INLINE hmm_quaternion HMM_DivideQuaternionF(hmm_quaternion Left, float Dividend)
{
    ASSERT_COVERED(HMM_DivideQuaternionF);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Dividend);
    Result.InternalElementsSSE = _mm_div_ps(Left.InternalElementsSSE, Scalar);
#else
    Result.X = Left.X / Dividend;
    Result.Y = Left.Y / Dividend;
    Result.Z = Left.Z / Dividend;
    Result.W = Left.W / Dividend;
#endif

    return (Result);
}

HMM_EXTERN hmm_quaternion HMM_InverseQuaternion(hmm_quaternion Left);

COVERAGE(HMM_DotQuaternion, 1)
HMM_INLINE float HMM_DotQuaternion(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_DotQuaternion);

    float Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_mul_ps(Left.InternalElementsSSE, Right.InternalElementsSSE);
    __m128 SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(0, 1, 2, 3));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    _mm_store_ss(&Result, SSEResultOne);
#else
    Result = (Left.X * Right.X) + (Left.Y * Right.Y) + (Left.Z * Right.Z) + (Left.W * Right.W);
#endif

    return (Result);
}

COVERAGE(HMM_NormalizeQuaternion, 1)
HMM_INLINE hmm_quaternion HMM_NormalizeQuaternion(hmm_quaternion Left)
{
    ASSERT_COVERED(HMM_NormalizeQuaternion);

    hmm_quaternion Result;

    float Length = HMM_SquareRootF(HMM_DotQuaternion(Left, Left));
    Result = HMM_DivideQuaternionF(Left, Length);

    return (Result);
}

COVERAGE(HMM_NLerp, 1)
HMM_INLINE hmm_quaternion HMM_NLerp(hmm_quaternion Left, float Time, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_NLerp);

    hmm_quaternion Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 ScalarLeft = _mm_set1_ps(1.0f - Time);
    __m128 ScalarRight = _mm_set1_ps(Time);
    __m128 SSEResultOne = _mm_mul_ps(Left.InternalElementsSSE, ScalarLeft);
    __m128 SSEResultTwo = _mm_mul_ps(Right.InternalElementsSSE, ScalarRight);
    Result.InternalElementsSSE = _mm_add_ps(SSEResultOne, SSEResultTwo);
#else
    Result.X = HMM_Lerp(Left.X, Time, Right.X);
    Result.Y = HMM_Lerp(Left.Y, Time, Right.Y);
    Result.Z = HMM_Lerp(Left.Z, Time, Right.Z);
    Result.W = HMM_Lerp(Left.W, Time, Right.W);
#endif
    Result = HMM_NormalizeQuaternion(Result);

    return (Result);
}

HMM_EXTERN hmm_quaternion HMM_Slerp(hmm_quaternion Left, float Time, hmm_quaternion Right);
HMM_EXTERN hmm_mat4 HMM_QuaternionToMat4(hmm_quaternion Left);
HMM_EXTERN hmm_quaternion HMM_Mat4ToQuaternion(hmm_mat4 Left);
HMM_EXTERN hmm_quaternion HMM_QuaternionFromAxisAngle(const hmm_vec3& Axis, float AngleOfRotation);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

COVERAGE(HMM_LengthVec2CPP, 1)
HMM_INLINE float HMM_Length(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_LengthVec2CPP);

    float Result = HMM_LengthVec2(A);

    return (Result);
}

COVERAGE(HMM_LengthVec3CPP, 1)
HMM_INLINE float HMM_Length(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_LengthVec3CPP);

    float Result = HMM_LengthVec3(A);

    return (Result);
}

COVERAGE(HMM_LengthVec4CPP, 1)
HMM_INLINE float HMM_Length(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_LengthVec4CPP);

    float Result = HMM_LengthVec4(A);

    return (Result);
}

COVERAGE(HMM_LengthSquaredVec2CPP, 1)
HMM_INLINE float HMM_LengthSquared(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec2CPP);

    float Result = HMM_LengthSquaredVec2(A);

    return (Result);
}

COVERAGE(HMM_LengthSquaredVec3CPP, 1)
HMM_INLINE float HMM_LengthSquared(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec3CPP);

    float Result = HMM_LengthSquaredVec3(A);

    return (Result);
}

COVERAGE(HMM_LengthSquaredVec4CPP, 1)
HMM_INLINE float HMM_LengthSquared(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_LengthSquaredVec4CPP);

    float Result = HMM_LengthSquaredVec4(A);

    return (Result);
}

COVERAGE(HMM_NormalizeVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_Normalize(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_NormalizeVec2CPP);

    hmm_vec2 Result = HMM_NormalizeVec2(A);

    return (Result);
}

COVERAGE(HMM_NormalizeVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_Normalize(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_NormalizeVec3CPP);

    hmm_vec3 Result = HMM_NormalizeVec3(A);

    return (Result);
}

COVERAGE(HMM_NormalizeVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Normalize(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_NormalizeVec4CPP);

    hmm_vec4 Result = HMM_NormalizeVec4(A);

    return (Result);
}

COVERAGE(HMM_FastNormalizeVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_FastNormalize(hmm_vec2 A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec2CPP);

    hmm_vec2 Result = HMM_FastNormalizeVec2(A);

    return (Result);
}

COVERAGE(HMM_FastNormalizeVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_FastNormalize(const hmm_vec3& A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec3CPP);

    hmm_vec3 Result = HMM_FastNormalizeVec3(A);

    return (Result);
}

COVERAGE(HMM_FastNormalizeVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_FastNormalize(hmm_vec4 A)
{
    ASSERT_COVERED(HMM_FastNormalizeVec4CPP);

    hmm_vec4 Result = HMM_FastNormalizeVec4(A);

    return (Result);
}

COVERAGE(HMM_NormalizeQuaternionCPP, 1)
HMM_INLINE hmm_quaternion HMM_Normalize(hmm_quaternion A)
{
    ASSERT_COVERED(HMM_NormalizeQuaternionCPP);

    hmm_quaternion Result = HMM_NormalizeQuaternion(A);

    return (Result);
}

COVERAGE(HMM_DotVec2CPP, 1)
HMM_INLINE float HMM_Dot(hmm_vec2 VecOne, hmm_vec2 VecTwo)
{
    ASSERT_COVERED(HMM_DotVec2CPP);

    float Result = HMM_DotVec2(VecOne, VecTwo);

    return (Result);
}

COVERAGE(HMM_DotVec3CPP, 1)
HMM_INLINE float HMM_Dot(const hmm_vec3& VecOne,const hmm_vec3& VecTwo)
{
    ASSERT_COVERED(HMM_DotVec3CPP);

    float Result = HMM_DotVec3(VecOne, VecTwo);

    return (Result);
}

COVERAGE(HMM_DotVec4CPP, 1)
HMM_INLINE float HMM_Dot(hmm_vec4 VecOne, hmm_vec4 VecTwo)
{
    ASSERT_COVERED(HMM_DotVec4CPP);

    float Result = HMM_DotVec4(VecOne, VecTwo);

    return (Result);
}

COVERAGE(HMM_DotQuaternionCPP, 1)
HMM_INLINE float HMM_Dot(hmm_quaternion QuatOne, hmm_quaternion QuatTwo)
{
    ASSERT_COVERED(HMM_DotQuaternionCPP);

    float Result = HMM_DotQuaternion(QuatOne, QuatTwo);

    return (Result);
}

COVERAGE(HMM_AddVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_Add(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_AddVec2CPP);

    hmm_vec2 Result = HMM_AddVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_Add(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_AddVec3CPP);

    hmm_vec3 Result = HMM_AddVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Add(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_AddVec4CPP);

    hmm_vec4 Result = HMM_AddVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddMat4CPP, 1)
HMM_INLINE hmm_mat4 HMM_Add(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_AddMat4CPP);

    hmm_mat4 Result = HMM_AddMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddQuaternionCPP, 1)
HMM_INLINE hmm_quaternion HMM_Add(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_AddQuaternionCPP);

    hmm_quaternion Result = HMM_AddQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_Subtract(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_SubtractVec2CPP);

    hmm_vec2 Result = HMM_SubtractVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_Subtract(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_SubtractVec3CPP);

    hmm_vec3 Result = HMM_SubtractVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Subtract(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_SubtractVec4CPP);

    hmm_vec4 Result = HMM_SubtractVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractMat4CPP, 1)
HMM_INLINE hmm_mat4 HMM_Subtract(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_SubtractMat4CPP);

    hmm_mat4 Result = HMM_SubtractMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractQuaternionCPP, 1)
HMM_INLINE hmm_quaternion HMM_Subtract(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_SubtractQuaternionCPP);

    hmm_quaternion Result = HMM_SubtractQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_Multiply(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2CPP);

    hmm_vec2 Result = HMM_MultiplyVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec2fCPP, 1)
HMM_INLINE hmm_vec2 HMM_Multiply(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2fCPP);

    hmm_vec2 Result = HMM_MultiplyVec2f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_Multiply(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3CPP);

    hmm_vec3 Result = HMM_MultiplyVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec3fCPP, 1)
HMM_INLINE hmm_vec3 HMM_Multiply(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3fCPP);

    hmm_vec3 Result = HMM_MultiplyVec3f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Multiply(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4CPP);

    hmm_vec4 Result = HMM_MultiplyVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec4fCPP, 1)
HMM_INLINE hmm_vec4 HMM_Multiply(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4fCPP);

    hmm_vec4 Result = HMM_MultiplyVec4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4CPP, 1)
HMM_INLINE hmm_mat4 HMM_Multiply(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4CPP);

    hmm_mat4 Result = HMM_MultiplyMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4fCPP, 1)
HMM_INLINE hmm_mat4 HMM_Multiply(hmm_mat4 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4fCPP);

    hmm_mat4 Result = HMM_MultiplyMat4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4ByVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Multiply(hmm_mat4 Matrix, hmm_vec4 Vector)
{
    ASSERT_COVERED(HMM_MultiplyMat4ByVec4CPP);

    hmm_vec4 Result = HMM_MultiplyMat4ByVec4(Matrix, Vector);

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionCPP, 1)
HMM_INLINE hmm_quaternion HMM_Multiply(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionCPP);

    hmm_quaternion Result = HMM_MultiplyQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionFCPP, 1)
HMM_INLINE hmm_quaternion HMM_Multiply(hmm_quaternion Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionFCPP);

    hmm_quaternion Result = HMM_MultiplyQuaternionF(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec2CPP, 1)
HMM_INLINE hmm_vec2 HMM_Divide(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_DivideVec2CPP);

    hmm_vec2 Result = HMM_DivideVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec2fCPP, 1)
HMM_INLINE hmm_vec2 HMM_Divide(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec2fCPP);

    hmm_vec2 Result = HMM_DivideVec2f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec3CPP, 1)
HMM_INLINE hmm_vec3 HMM_Divide(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_DivideVec3CPP);

    hmm_vec3 Result = HMM_DivideVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec3fCPP, 1)
HMM_INLINE hmm_vec3 HMM_Divide(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec3fCPP);

    hmm_vec3 Result = HMM_DivideVec3f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec4CPP, 1)
HMM_INLINE hmm_vec4 HMM_Divide(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_DivideVec4CPP);

    hmm_vec4 Result = HMM_DivideVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec4fCPP, 1)
HMM_INLINE hmm_vec4 HMM_Divide(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec4fCPP);

    hmm_vec4 Result = HMM_DivideVec4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideMat4fCPP, 1)
HMM_INLINE hmm_mat4 HMM_Divide(hmm_mat4 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideMat4fCPP);

    hmm_mat4 Result = HMM_DivideMat4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideQuaternionFCPP, 1)
HMM_INLINE hmm_quaternion HMM_Divide(hmm_quaternion Left, float Right)
{
    ASSERT_COVERED(HMM_DivideQuaternionFCPP);

    hmm_quaternion Result = HMM_DivideQuaternionF(Left, Right);

    return (Result);
}

COVERAGE(HMM_EqualsVec2CPP, 1)
HMM_INLINE hmm_bool HMM_Equals(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_EqualsVec2CPP);

    hmm_bool Result = HMM_EqualsVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_EqualsVec3CPP, 1)
HMM_INLINE hmm_bool HMM_Equals(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_EqualsVec3CPP);

    hmm_bool Result = HMM_EqualsVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_EqualsVec4CPP, 1)
HMM_INLINE hmm_bool HMM_Equals(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_EqualsVec4CPP);

    hmm_bool Result = HMM_EqualsVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddVec2Op, 1)
HMM_INLINE hmm_vec2 operator+(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_AddVec2Op);

    hmm_vec2 Result = HMM_AddVec2(Left, Right);

    return (Result);
}

HMM_INLINE hmm_vec3 operator-(const hmm_vec3& Left ){
  return { -Left[0], -Left[1], -Left[2] };
}

COVERAGE(HMM_AddVec3Op, 1)
HMM_INLINE hmm_vec3 operator+(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_AddVec3Op);

    hmm_vec3 Result = HMM_AddVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddVec4Op, 1)
HMM_INLINE hmm_vec4 operator+(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_AddVec4Op);

    hmm_vec4 Result = HMM_AddVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddMat4Op, 1)
HMM_INLINE hmm_mat4 operator+(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_AddMat4Op);

    hmm_mat4 Result = HMM_AddMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddQuaternionOp, 1)
HMM_INLINE hmm_quaternion operator+(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_AddQuaternionOp);

    hmm_quaternion Result = HMM_AddQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec2Op, 1)
HMM_INLINE hmm_vec2 operator-(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_SubtractVec2Op);

    hmm_vec2 Result = HMM_SubtractVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec3Op, 1)
HMM_INLINE hmm_vec3 operator-(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_SubtractVec3Op);

    hmm_vec3 Result = HMM_SubtractVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractVec4Op, 1)
HMM_INLINE hmm_vec4 operator-(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_SubtractVec4Op);

    hmm_vec4 Result = HMM_SubtractVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractMat4Op, 1)
HMM_INLINE hmm_mat4 operator-(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_SubtractMat4Op);

    hmm_mat4 Result = HMM_SubtractMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_SubtractQuaternionOp, 1)
HMM_INLINE hmm_quaternion operator-(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_SubtractQuaternionOp);

    hmm_quaternion Result = HMM_SubtractQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec2Op, 1)
HMM_INLINE hmm_vec2 operator*(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2Op);

    hmm_vec2 Result = HMM_MultiplyVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec3Op, 1)
HMM_INLINE hmm_vec3 operator*(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3Op);

    hmm_vec3 Result = HMM_MultiplyVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec4Op, 1)
HMM_INLINE hmm_vec4 operator*(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4Op);

    hmm_vec4 Result = HMM_MultiplyVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4Op, 1)
HMM_INLINE hmm_mat4 operator*(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4Op);

    hmm_mat4 Result = HMM_MultiplyMat4(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionOp, 1)
HMM_INLINE hmm_quaternion operator*(hmm_quaternion Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionOp);

    hmm_quaternion Result = HMM_MultiplyQuaternion(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec2fOp, 1)
HMM_INLINE hmm_vec2 operator*(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2fOp);

    hmm_vec2 Result = HMM_MultiplyVec2f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec3fOp, 1)
HMM_INLINE hmm_vec3 operator*(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3fOp);

    hmm_vec3 Result = HMM_MultiplyVec3f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec4fOp, 1)
HMM_INLINE hmm_vec4 operator*(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4fOp);

    hmm_vec4 Result = HMM_MultiplyVec4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4fOp, 1)
HMM_INLINE hmm_mat4 operator*(hmm_mat4 Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4fOp);

    hmm_mat4 Result = HMM_MultiplyMat4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionFOp, 1)
HMM_INLINE hmm_quaternion operator*(hmm_quaternion Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionFOp);

    hmm_quaternion Result = HMM_MultiplyQuaternionF(Left, Right);

    return (Result);
}

COVERAGE(HMM_MultiplyVec2fOpLeft, 1)
HMM_INLINE hmm_vec2 operator*(float Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2fOpLeft);

    hmm_vec2 Result = HMM_MultiplyVec2f(Right, Left);

    return (Result);
}

COVERAGE(HMM_MultiplyVec3fOpLeft, 1)
HMM_INLINE hmm_vec3 operator*(float Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3fOpLeft);

    hmm_vec3 Result = HMM_MultiplyVec3f(Right, Left);

    return (Result);
}

COVERAGE(HMM_MultiplyVec4fOpLeft, 1)
HMM_INLINE hmm_vec4 operator*(float Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4fOpLeft);

    hmm_vec4 Result = HMM_MultiplyVec4f(Right, Left);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4fOpLeft, 1)
HMM_INLINE hmm_mat4 operator*(float Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4fOpLeft);

    hmm_mat4 Result = HMM_MultiplyMat4f(Right, Left);

    return (Result);
}

COVERAGE(HMM_MultiplyQuaternionFOpLeft, 1)
HMM_INLINE hmm_quaternion operator*(float Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionFOpLeft);

    hmm_quaternion Result = HMM_MultiplyQuaternionF(Right, Left);

    return (Result);
}

COVERAGE(HMM_MultiplyMat4ByVec4Op, 1)
HMM_INLINE hmm_vec4 operator*(hmm_mat4 Matrix, hmm_vec4 Vector)
{
    ASSERT_COVERED(HMM_MultiplyMat4ByVec4Op);

    hmm_vec4 Result = HMM_MultiplyMat4ByVec4(Matrix, Vector);

    return (Result);
}

COVERAGE(HMM_DivideVec2Op, 1)
HMM_INLINE hmm_vec2 operator/(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_DivideVec2Op);

    hmm_vec2 Result = HMM_DivideVec2(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec3Op, 1)
HMM_INLINE hmm_vec3 operator/(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_DivideVec3Op);

    hmm_vec3 Result = HMM_DivideVec3(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec4Op, 1)
HMM_INLINE hmm_vec4 operator/(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_DivideVec4Op);

    hmm_vec4 Result = HMM_DivideVec4(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec2fOp, 1)
HMM_INLINE hmm_vec2 operator/(hmm_vec2 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec2fOp);

    hmm_vec2 Result = HMM_DivideVec2f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec3fOp, 1)
HMM_INLINE hmm_vec3 operator/(const hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec3fOp);

    hmm_vec3 Result = HMM_DivideVec3f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideVec4fOp, 1)
HMM_INLINE hmm_vec4 operator/(hmm_vec4 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec4fOp);

    hmm_vec4 Result = HMM_DivideVec4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideMat4fOp, 1)
HMM_INLINE hmm_mat4 operator/(hmm_mat4 Left, float Right)
{
    ASSERT_COVERED(HMM_DivideMat4fOp);

    hmm_mat4 Result = HMM_DivideMat4f(Left, Right);

    return (Result);
}

COVERAGE(HMM_DivideQuaternionFOp, 1)
HMM_INLINE hmm_quaternion operator/(hmm_quaternion Left, float Right)
{
    ASSERT_COVERED(HMM_DivideQuaternionFOp);

    hmm_quaternion Result = HMM_DivideQuaternionF(Left, Right);

    return (Result);
}

COVERAGE(HMM_AddVec2Assign, 1)
HMM_INLINE hmm_vec2 &operator+=(hmm_vec2 &Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_AddVec2Assign);

    return (Left = Left + Right);
}

COVERAGE(HMM_AddVec3Assign, 1)
HMM_INLINE hmm_vec3 &operator+=(hmm_vec3 &Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_AddVec3Assign);

    return (Left = Left + Right);
}

COVERAGE(HMM_AddVec4Assign, 1)
HMM_INLINE hmm_vec4 &operator+=(hmm_vec4 &Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_AddVec4Assign);

    return (Left = Left + Right);
}

COVERAGE(HMM_AddMat4Assign, 1)
HMM_INLINE hmm_mat4 &operator+=(hmm_mat4 &Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_AddMat4Assign);

    return (Left = Left + Right);
}

COVERAGE(HMM_AddQuaternionAssign, 1)
HMM_INLINE hmm_quaternion &operator+=(hmm_quaternion &Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_AddQuaternionAssign);

    return (Left = Left + Right);
}

COVERAGE(HMM_SubtractVec2Assign, 1)
HMM_INLINE hmm_vec2 &operator-=(hmm_vec2 &Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_SubtractVec2Assign);

    return (Left = Left - Right);
}

COVERAGE(HMM_SubtractVec3Assign, 1)
HMM_INLINE hmm_vec3 &operator-=(hmm_vec3 &Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_SubtractVec3Assign);

    return (Left = Left - Right);
}

COVERAGE(HMM_SubtractVec4Assign, 1)
HMM_INLINE hmm_vec4 &operator-=(hmm_vec4 &Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_SubtractVec4Assign);

    return (Left = Left - Right);
}

COVERAGE(HMM_SubtractMat4Assign, 1)
HMM_INLINE hmm_mat4 &operator-=(hmm_mat4 &Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_SubtractMat4Assign);

    return (Left = Left - Right);
}

COVERAGE(HMM_SubtractQuaternionAssign, 1)
HMM_INLINE hmm_quaternion &operator-=(hmm_quaternion &Left, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_SubtractQuaternionAssign);

    return (Left = Left - Right);
}

COVERAGE(HMM_MultiplyVec2Assign, 1)
HMM_INLINE hmm_vec2 &operator*=(hmm_vec2 &Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2Assign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyVec3Assign, 1)
HMM_INLINE hmm_vec3 &operator*=(hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3Assign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyVec4Assign, 1)
HMM_INLINE hmm_vec4 &operator*=(hmm_vec4 &Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4Assign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyVec2fAssign, 1)
HMM_INLINE hmm_vec2 &operator*=(hmm_vec2 &Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec2fAssign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyVec3fAssign, 1)
HMM_INLINE hmm_vec3 &operator*=(hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec3fAssign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyVec4fAssign, 1)
HMM_INLINE hmm_vec4 &operator*=(hmm_vec4 &Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyVec4fAssign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyMat4fAssign, 1)
HMM_INLINE hmm_mat4 &operator*=(hmm_mat4 &Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4fAssign);

    return (Left = Left * Right);
}

COVERAGE(HMM_MultiplyQuaternionFAssign, 1)
HMM_INLINE hmm_quaternion &operator*=(hmm_quaternion &Left, float Right)
{
    ASSERT_COVERED(HMM_MultiplyQuaternionFAssign);

    return (Left = Left * Right);
}

COVERAGE(HMM_DivideVec2Assign, 1)
HMM_INLINE hmm_vec2 &operator/=(hmm_vec2 &Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_DivideVec2Assign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideVec3Assign, 1)
HMM_INLINE hmm_vec3 &operator/=(hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_DivideVec3Assign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideVec4Assign, 1)
HMM_INLINE hmm_vec4 &operator/=(hmm_vec4 &Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_DivideVec4Assign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideVec2fAssign, 1)
HMM_INLINE hmm_vec2 &operator/=(hmm_vec2 &Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec2fAssign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideVec3fAssign, 1)
HMM_INLINE hmm_vec3 &operator/=(hmm_vec3& Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec3fAssign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideVec4fAssign, 1)
HMM_INLINE hmm_vec4 &operator/=(hmm_vec4 &Left, float Right)
{
    ASSERT_COVERED(HMM_DivideVec4fAssign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideMat4fAssign, 1)
HMM_INLINE hmm_mat4 &operator/=(hmm_mat4 &Left, float Right)
{
    ASSERT_COVERED(HMM_DivideMat4fAssign);

    return (Left = Left / Right);
}

COVERAGE(HMM_DivideQuaternionFAssign, 1)
HMM_INLINE hmm_quaternion &operator/=(hmm_quaternion &Left, float Right)
{
    ASSERT_COVERED(HMM_DivideQuaternionFAssign);

    return (Left = Left / Right);
}

COVERAGE(HMM_EqualsVec2Op, 1)
HMM_INLINE hmm_bool operator==(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_EqualsVec2Op);

    return HMM_EqualsVec2(Left, Right);
}

COVERAGE(HMM_EqualsVec3Op, 1)
HMM_INLINE hmm_bool operator==(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_EqualsVec3Op);

    return HMM_EqualsVec3(Left, Right);
}

COVERAGE(HMM_EqualsVec4Op, 1)
HMM_INLINE hmm_bool operator==(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_EqualsVec4Op);

    return HMM_EqualsVec4(Left, Right);
}

COVERAGE(HMM_EqualsVec2OpNot, 1)
HMM_INLINE hmm_bool operator!=(hmm_vec2 Left, hmm_vec2 Right)
{
    ASSERT_COVERED(HMM_EqualsVec2OpNot);

    return !HMM_EqualsVec2(Left, Right);
}

COVERAGE(HMM_EqualsVec3OpNot, 1)
HMM_INLINE hmm_bool operator!=(const hmm_vec3& Left,const hmm_vec3& Right)
{
    ASSERT_COVERED(HMM_EqualsVec3OpNot);

    return !HMM_EqualsVec3(Left, Right);
}

COVERAGE(HMM_EqualsVec4OpNot, 1)
HMM_INLINE hmm_bool operator!=(hmm_vec4 Left, hmm_vec4 Right)
{
    ASSERT_COVERED(HMM_EqualsVec4OpNot);

    return !HMM_EqualsVec4(Left, Right);
}

#endif /* __cplusplus */

#ifdef __clang__
#pragma GCC diagnostic pop
#endif

#if defined(__GNUC__) && (__GNUC__ == 4 && __GNUC_MINOR__ < 8)
#pragma GCC diagnostic pop
#endif

#endif /* HANDMADE_MATH_H */

#ifdef HANDMADE_MATH_IMPLEMENTATION

COVERAGE(HMM_Power, 2)
float HMM_Power(float Base, int Exponent)
{
    ASSERT_COVERED(HMM_Power);

    float Result = 1.0f;
    float Mul = Exponent < 0 ? 1.f / Base : Base;
    int X = Exponent < 0 ? -Exponent : Exponent;
    while (X)
    {
        if (X & 1)
        {
            ASSERT_COVERED(HMM_Power);

            Result *= Mul;
        }

        Mul *= Mul;
        X >>= 1;
    }

    return (Result);
}

#ifndef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_Transpose, 1)
hmm_mat4 HMM_Transpose(hmm_mat4 Matrix)
{
    ASSERT_COVERED(HMM_Transpose);

    hmm_mat4 Result;

    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            Result.Elements[Rows][Columns] = Matrix.Elements[Columns][Rows];
        }
    }

    return (Result);
}
#endif

#ifndef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_AddMat4, 1)
hmm_mat4 HMM_AddMat4(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_AddMat4);

    hmm_mat4 Result;

    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            Result.Elements[Columns][Rows] = Left.Elements[Columns][Rows] + Right.Elements[Columns][Rows];
        }
    }

    return (Result);
}
#endif

#ifndef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_SubtractMat4, 1)
hmm_mat4 HMM_SubtractMat4(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_SubtractMat4);

    hmm_mat4 Result;

    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            Result.Elements[Columns][Rows] = Left.Elements[Columns][Rows] - Right.Elements[Columns][Rows];
        }
    }

    return (Result);
}
#endif

COVERAGE(HMM_MultiplyMat4, 1)
hmm_mat4 HMM_MultiplyMat4(hmm_mat4 Left, hmm_mat4 Right)
{
    ASSERT_COVERED(HMM_MultiplyMat4);

    hmm_mat4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.Columns[0] = HMM_LinearCombineSSE(Right.Columns[0], Left);
    Result.Columns[1] = HMM_LinearCombineSSE(Right.Columns[1], Left);
    Result.Columns[2] = HMM_LinearCombineSSE(Right.Columns[2], Left);
    Result.Columns[3] = HMM_LinearCombineSSE(Right.Columns[3], Left);
#else
    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            float Sum = 0;
            int CurrentMatrice;
            for(CurrentMatrice = 0; CurrentMatrice < 4; ++CurrentMatrice)
            {
                Sum += Left.Elements[CurrentMatrice][Rows] * Right.Elements[Columns][CurrentMatrice];
            }

            Result.Elements[Columns][Rows] = Sum;
        }
    }
#endif

    return (Result);
}

#ifndef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_MultiplyMat4f, 1)
hmm_mat4 HMM_MultiplyMat4f(hmm_mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(HMM_MultiplyMat4f);

    hmm_mat4 Result;

    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            Result.Elements[Columns][Rows] = Matrix.Elements[Columns][Rows] * Scalar;
        }
    }

    return (Result);
}
#endif

COVERAGE(HMM_MultiplyMat4ByVec4, 1)
hmm_vec4 HMM_MultiplyMat4ByVec4(hmm_mat4 Matrix, hmm_vec4 Vector)
{
    ASSERT_COVERED(HMM_MultiplyMat4ByVec4);

    hmm_vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
	Result.InternalElementsSSE = HMM_LinearCombineSSE(Vector.InternalElementsSSE, Matrix);
#else
    int Columns, Rows;
    for(Rows = 0; Rows < 4; ++Rows)
    {
        float Sum = 0;
        for(Columns = 0; Columns < 4; ++Columns)
        {
            Sum += Matrix.Elements[Columns][Rows] * Vector.Elements[Columns];
        }

        Result.Elements[Rows] = Sum;
    }
#endif

    return (Result);
}

#ifndef HANDMADE_MATH__USE_SSE
COVERAGE(HMM_DivideMat4f, 1);
hmm_mat4 HMM_DivideMat4f(hmm_mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(HMM_DivideMat4f);

    hmm_mat4 Result;

    int Columns;
    for(Columns = 0; Columns < 4; ++Columns)
    {
        int Rows;
        for(Rows = 0; Rows < 4; ++Rows)
        {
            Result.Elements[Columns][Rows] = Matrix.Elements[Columns][Rows] / Scalar;
        }
    }

    return (Result);
}
#endif

COVERAGE(HMM_Rotate, 1)
hmm_mat4 HMM_Rotate(float Angle,hmm_vec3 Axis)
{
    ASSERT_COVERED(HMM_Rotate);

    hmm_mat4 Result = HMM_Mat4d(1.0f);

    Axis = HMM_NormalizeVec3(Axis);

    float SinTheta = HMM_SinF(HMM_ToRadians(Angle));
    float CosTheta = HMM_CosF(HMM_ToRadians(Angle));
    float CosValue = 1.0f - CosTheta;

    Result.Elements[0][0] = (Axis.X * Axis.X * CosValue) + CosTheta;
    Result.Elements[0][1] = (Axis.X * Axis.Y * CosValue) + (Axis.Z * SinTheta);
    Result.Elements[0][2] = (Axis.X * Axis.Z * CosValue) - (Axis.Y * SinTheta);

    Result.Elements[1][0] = (Axis.Y * Axis.X * CosValue) - (Axis.Z * SinTheta);
    Result.Elements[1][1] = (Axis.Y * Axis.Y * CosValue) + CosTheta;
    Result.Elements[1][2] = (Axis.Y * Axis.Z * CosValue) + (Axis.X * SinTheta);

    Result.Elements[2][0] = (Axis.Z * Axis.X * CosValue) + (Axis.Y * SinTheta);
    Result.Elements[2][1] = (Axis.Z * Axis.Y * CosValue) - (Axis.X * SinTheta);
    Result.Elements[2][2] = (Axis.Z * Axis.Z * CosValue) + CosTheta;

    return (Result);
}

COVERAGE(HMM_LookAt, 1)
hmm_mat4 HMM_LookAt(const hmm_vec3& Eye,const hmm_vec3& Center,const hmm_vec3& Up)
{
    ASSERT_COVERED(HMM_LookAt);

    hmm_mat4 Result;

    hmm_vec3 F = HMM_NormalizeVec3(HMM_SubtractVec3(Center, Eye));
    hmm_vec3 S = HMM_NormalizeVec3(HMM_Cross(F, Up));
    hmm_vec3 U = HMM_Cross(S, F);

    Result.Elements[0][0] = S.X;
    Result.Elements[0][1] = U.X;
    Result.Elements[0][2] = -F.X;
    Result.Elements[0][3] = 0.0f;

    Result.Elements[1][0] = S.Y;
    Result.Elements[1][1] = U.Y;
    Result.Elements[1][2] = -F.Y;
    Result.Elements[1][3] = 0.0f;

    Result.Elements[2][0] = S.Z;
    Result.Elements[2][1] = U.Z;
    Result.Elements[2][2] = -F.Z;
    Result.Elements[2][3] = 0.0f;

    Result.Elements[3][0] = -HMM_DotVec3(S, Eye);
    Result.Elements[3][1] = -HMM_DotVec3(U, Eye);
    Result.Elements[3][2] = HMM_DotVec3(F, Eye);
    Result.Elements[3][3] = 1.0f;

    return (Result);
}

COVERAGE(HMM_InverseQuaternion, 1)
hmm_quaternion HMM_InverseQuaternion(hmm_quaternion Left)
{
    ASSERT_COVERED(HMM_InverseQuaternion);

    hmm_quaternion Conjugate;
    hmm_quaternion Result;
    float Norm = 0;
    float NormSquared = 0;

    Conjugate.X = -Left.X;
    Conjugate.Y = -Left.Y;
    Conjugate.Z = -Left.Z;
    Conjugate.W = Left.W;

    Norm = HMM_SquareRootF(HMM_DotQuaternion(Left, Left));
    NormSquared = Norm * Norm;

    Result = HMM_DivideQuaternionF(Conjugate, NormSquared);

    return (Result);
}

COVERAGE(HMM_Slerp, 1)
hmm_quaternion HMM_Slerp(hmm_quaternion Left, float Time, hmm_quaternion Right)
{
    ASSERT_COVERED(HMM_Slerp);

    hmm_quaternion Result;
    hmm_quaternion QuaternionLeft;
    hmm_quaternion QuaternionRight;

    float Cos_Theta = HMM_DotQuaternion(Left, Right);
    float Angle = HMM_ACosF(Cos_Theta);

    float S1 = HMM_SinF((1.0f - Time) * Angle);
    float S2 = HMM_SinF(Time * Angle);
    float Is = 1.0f / HMM_SinF(Angle);

    QuaternionLeft = HMM_MultiplyQuaternionF(Left, S1);
    QuaternionRight = HMM_MultiplyQuaternionF(Right, S2);

    Result = HMM_AddQuaternion(QuaternionLeft, QuaternionRight);
    Result = HMM_MultiplyQuaternionF(Result, Is);

    return (Result);
}

COVERAGE(HMM_QuaternionToMat4, 1)
hmm_mat4 HMM_QuaternionToMat4(hmm_quaternion Left)
{
    ASSERT_COVERED(HMM_QuaternionToMat4);

    hmm_mat4 Result;

    hmm_quaternion NormalizedQuaternion = HMM_NormalizeQuaternion(Left);

    float XX, YY, ZZ,
          XY, XZ, YZ,
          WX, WY, WZ;

    XX = NormalizedQuaternion.X * NormalizedQuaternion.X;
    YY = NormalizedQuaternion.Y * NormalizedQuaternion.Y;
    ZZ = NormalizedQuaternion.Z * NormalizedQuaternion.Z;
    XY = NormalizedQuaternion.X * NormalizedQuaternion.Y;
    XZ = NormalizedQuaternion.X * NormalizedQuaternion.Z;
    YZ = NormalizedQuaternion.Y * NormalizedQuaternion.Z;
    WX = NormalizedQuaternion.W * NormalizedQuaternion.X;
    WY = NormalizedQuaternion.W * NormalizedQuaternion.Y;
    WZ = NormalizedQuaternion.W * NormalizedQuaternion.Z;

    Result.Elements[0][0] = 1.0f - 2.0f * (YY + ZZ);
    Result.Elements[0][1] = 2.0f * (XY + WZ);
    Result.Elements[0][2] = 2.0f * (XZ - WY);
    Result.Elements[0][3] = 0.0f;

    Result.Elements[1][0] = 2.0f * (XY - WZ);
    Result.Elements[1][1] = 1.0f - 2.0f * (XX + ZZ);
    Result.Elements[1][2] = 2.0f * (YZ + WX);
    Result.Elements[1][3] = 0.0f;

    Result.Elements[2][0] = 2.0f * (XZ + WY);
    Result.Elements[2][1] = 2.0f * (YZ - WX);
    Result.Elements[2][2] = 1.0f - 2.0f * (XX + YY);
    Result.Elements[2][3] = 0.0f;

    Result.Elements[3][0] = 0.0f;
    Result.Elements[3][1] = 0.0f;
    Result.Elements[3][2] = 0.0f;
    Result.Elements[3][3] = 1.0f;

    return (Result);
}

// This method taken from Mike Day at Insomniac Games.
// https://d3cw3dd2w32x2b.cloudfront.net/wp-content/uploads/2015/01/matrix-to-quat.pdf
//
// Note that as mentioned at the top of the paper, the paper assumes the matrix
// would be *post*-multiplied to a vector to rotate it, meaning the matrix is
// the transpose of what we're dealing with. But, because our matrices are
// stored in column-major order, the indices *appear* to match the paper.
//
// For example, m12 in the paper is row 1, column 2. We need to transpose it to
// row 2, column 1. But, because the column comes first when referencing
// elements, it looks like M.Elements[1][2].
//
// Don't be confused! Or if you must be confused, at least trust this
// comment. :)
COVERAGE(HMM_Mat4ToQuaternion, 4)
hmm_quaternion HMM_Mat4ToQuaternion(hmm_mat4 M)
{
    float T;
    hmm_quaternion Q;

    if (M.Elements[2][2] < 0.0f) {
        if (M.Elements[0][0] > M.Elements[1][1]) {
            ASSERT_COVERED(HMM_Mat4ToQuaternion);

            T = 1 + M.Elements[0][0] - M.Elements[1][1] - M.Elements[2][2];
            Q = HMM_Quaternion(
                T,
                M.Elements[0][1] + M.Elements[1][0],
                M.Elements[2][0] + M.Elements[0][2],
                M.Elements[1][2] - M.Elements[2][1]
            );
        } else {
            ASSERT_COVERED(HMM_Mat4ToQuaternion);

            T = 1 - M.Elements[0][0] + M.Elements[1][1] - M.Elements[2][2];
            Q = HMM_Quaternion(
                M.Elements[0][1] + M.Elements[1][0],
                T,
                M.Elements[1][2] + M.Elements[2][1],
                M.Elements[2][0] - M.Elements[0][2]
            );
        }
    } else {
        if (M.Elements[0][0] < -M.Elements[1][1]) {
            ASSERT_COVERED(HMM_Mat4ToQuaternion);

            T = 1 - M.Elements[0][0] - M.Elements[1][1] + M.Elements[2][2];
            Q = HMM_Quaternion(
                M.Elements[2][0] + M.Elements[0][2],
                M.Elements[1][2] + M.Elements[2][1],
                T,
                M.Elements[0][1] - M.Elements[1][0]
            );
        } else {
            ASSERT_COVERED(HMM_Mat4ToQuaternion);

            T = 1 + M.Elements[0][0] + M.Elements[1][1] + M.Elements[2][2];
            Q = HMM_Quaternion(
                M.Elements[1][2] - M.Elements[2][1],
                M.Elements[2][0] - M.Elements[0][2],
                M.Elements[0][1] - M.Elements[1][0],
                T
            );
        }
    }

    Q = HMM_MultiplyQuaternionF(Q, 0.5f / HMM_SquareRootF(T));

    return Q;
}

COVERAGE(HMM_QuaternionFromAxisAngle, 1)
hmm_quaternion HMM_QuaternionFromAxisAngle(const hmm_vec3& Axis, float AngleOfRotation)
{
    ASSERT_COVERED(HMM_QuaternionFromAxisAngle);

    hmm_quaternion Result;

    hmm_vec3 AxisNormalized = HMM_NormalizeVec3(Axis);
    float SineOfRotation = HMM_SinF(AngleOfRotation / 2.0f);

    Result.XYZ = HMM_MultiplyVec3f(AxisNormalized, SineOfRotation);
    Result.W = HMM_CosF(AngleOfRotation / 2.0f);

    return (Result);
}

HMM_INLINE hmm_vec3 HMM_Reflect(const hmm_vec3& v ,const hmm_vec3& n ){
  return  v - 2 * HMM_DotVec3( v, n ) * n;
}


// Matrix inversion code taken from
// https://lxjk.github.io/2017/09/03/Fast-4x4-Matrix-Inverse-with-SSE-SIMD-Explained.html



#define MakeShuffleMask(x,y,z,w)           (x | (y<<2) | (z<<4) | (w<<6))

// vec(0, 1, 2, 3) -> (vec[x], vec[y], vec[z], vec[w])
#define VecSwizzleMask(vec, mask)          _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(vec), mask))
#define VecSwizzle(vec, x, y, z, w)        VecSwizzleMask(vec, MakeShuffleMask(x,y,z,w))
#define VecSwizzle1(vec, x)                VecSwizzleMask(vec, MakeShuffleMask(x,x,x,x))
// special swizzle
#define VecSwizzle_0022(vec)               _mm_moveldup_ps(vec)
#define VecSwizzle_1133(vec)               _mm_movehdup_ps(vec)

// return (vec1[x], vec1[y], vec2[z], vec2[w])
#define VecShuffle(vec1, vec2, x,y,z,w)    _mm_shuffle_ps(vec1, vec2, MakeShuffleMask(x,y,z,w))
// special shuffle
#define VecShuffle_0101(vec1, vec2)        _mm_movelh_ps(vec1, vec2)
#define VecShuffle_2323(vec1, vec2)        _mm_movehl_ps(vec2, vec1)



// for column major matrix
// we use __m128 to represent 2x2 matrix as A = | A0  A2 |
//                                              | A1  A3 |
// 2x2 column major Matrix multiply A*B
inline __m128 Mat2Mul(__m128 vec1, __m128 vec2)
{
	return
		_mm_add_ps(_mm_mul_ps(                     vec1, VecSwizzle(vec2, 0,0,3,3)),
		           _mm_mul_ps(VecSwizzle(vec1, 2,3,0,1), VecSwizzle(vec2, 1,1,2,2)));
}
// 2x2 column major Matrix adjugate multiply (A#)*B
__m128 Mat2AdjMul(__m128 vec1, __m128 vec2)
{
	return
		_mm_sub_ps(_mm_mul_ps(VecSwizzle(vec1, 3,0,3,0), vec2),
		           _mm_mul_ps(VecSwizzle(vec1, 2,1,2,1), VecSwizzle(vec2, 1,0,3,2)));

}
// 2x2 column major Matrix multiply adjugate A*(B#)
__m128 Mat2MulAdj(__m128 vec1, __m128 vec2)
{
	return
		_mm_sub_ps(_mm_mul_ps(                     vec1, VecSwizzle(vec2, 3,3,0,0)),
		           _mm_mul_ps(VecSwizzle(vec1, 2,3,0,1), VecSwizzle(vec2, 1,1,2,2)));
}

// Inverse function is the same no matter column major or row major
// this version treats it as column major
inline hmm_mat4 GetInverse(const hmm_mat4 & inM)
{
	// use block matrix method
	// A is a matrix, then i(A) or iA means inverse of A, A# (or A_ in code) means adjugate of A, |A| (or detA in code) is determinant, tr(A) is trace

	// sub matrices
	__m128 A = VecShuffle_0101(inM.Columns[0], inM.Columns[1]);
	__m128 C = VecShuffle_2323(inM.Columns[0], inM.Columns[1]);
	__m128 B = VecShuffle_0101(inM.Columns[2], inM.Columns[3]);
	__m128 D = VecShuffle_2323(inM.Columns[2], inM.Columns[3]);

#if 0
	__m128 detA = _mm_set1_ps(inM.m[0][0] * inM.m[1][1] - inM.m[0][1] * inM.m[1][0]);
	__m128 detC = _mm_set1_ps(inM.m[0][2] * inM.m[1][3] - inM.m[0][3] * inM.m[1][2]);
	__m128 detB = _mm_set1_ps(inM.m[2][0] * inM.m[3][1] - inM.m[2][1] * inM.m[3][0]);
	__m128 detD = _mm_set1_ps(inM.m[2][2] * inM.m[3][3] - inM.m[2][3] * inM.m[3][2]);
#else
	// determinant as (|A| |C| |B| |D|)
	__m128 detSub = _mm_sub_ps(
		_mm_mul_ps(VecShuffle(inM.Columns[0], inM.Columns[2], 0,2,0,2), VecShuffle(inM.Columns[1], inM.Columns[3], 1,3,1,3)),
		_mm_mul_ps(VecShuffle(inM.Columns[0], inM.Columns[2], 1,3,1,3), VecShuffle(inM.Columns[1], inM.Columns[3], 0,2,0,2))
		);
	__m128 detA = VecSwizzle1(detSub, 0);
	__m128 detC = VecSwizzle1(detSub, 1);
	__m128 detB = VecSwizzle1(detSub, 2);
	__m128 detD = VecSwizzle1(detSub, 3);
#endif

	// let iM = 1/|M| * | X  Y |
	//                  | Z  W |

	// D#C
	__m128 D_C = Mat2AdjMul(D, C);
	// A#B
	__m128 A_B = Mat2AdjMul(A, B);
	// X# = |D|A - B(D#C)
	__m128 X_ = _mm_sub_ps(_mm_mul_ps(detD, A), Mat2Mul(B, D_C));
	// W# = |A|D - C(A#B)
	__m128 W_ = _mm_sub_ps(_mm_mul_ps(detA, D), Mat2Mul(C, A_B));

	// |M| = |A|*|D| + ... (continue later)
	__m128 detM = _mm_mul_ps(detA, detD);

	// Y# = |B|C - D(A#B)#
	__m128 Y_ = _mm_sub_ps(_mm_mul_ps(detB, C), Mat2MulAdj(D, A_B));
	// Z# = |C|B - A(D#C)#
	__m128 Z_ = _mm_sub_ps(_mm_mul_ps(detC, B), Mat2MulAdj(A, D_C));

	// |M| = |A|*|D| + |B|*|C| ... (continue later)
	detM = _mm_add_ps(detM, _mm_mul_ps(detB, detC));

	// tr((A#B)(D#C))
	__m128 tr = _mm_mul_ps(A_B, VecSwizzle(D_C, 0,2,1,3));
	tr = _mm_hadd_ps(tr, tr);
	tr = _mm_hadd_ps(tr, tr);
	// |M| = |A|*|D| + |B|*|C| - tr((A#B)(D#C))
	detM = _mm_sub_ps(detM, tr);

	const __m128 adjSignMask = _mm_setr_ps(1.f, -1.f, -1.f, 1.f);
	// (1/|M|, -1/|M|, -1/|M|, 1/|M|)
	__m128 rDetM = _mm_div_ps(adjSignMask, detM);

	X_ = _mm_mul_ps(X_, rDetM);
	Y_ = _mm_mul_ps(Y_, rDetM);
	Z_ = _mm_mul_ps(Z_, rDetM);
	W_ = _mm_mul_ps(W_, rDetM);

	hmm_mat4 r;

	// apply adjugate and store, here we combine adjugate shuffle and store shuffle
	r.Columns[0]= VecShuffle(X_, Z_, 3,1,3,1);
	r.Columns[1]= VecShuffle(X_, Z_, 2,0,2,0);
	r.Columns[2]= VecShuffle(Y_, W_, 3,1,3,1);
	r.Columns[3]= VecShuffle(Y_, W_, 2,0,2,0);

	return r;
}

hmm_vec3 HMM_UnProject(
    const hmm_vec3 &pos,
    const hmm_mat4 &vp, 
    int width, int height )
{
  hmm_mat4 inv = GetInverse( vp );
  hmm_vec4 point = { -1 + 2.0f * pos.X/width,
                     1 -2.0f * pos.Y/ height,
                     0.0f,
                     1.0f };
  hmm_vec4 x = inv * point;
  x /= x[3];
  return x.XYZ;
}

