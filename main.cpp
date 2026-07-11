#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <Vector.hpp>
#include <Matrix.hpp>
#include <doctest.h>
#include <iostream>

TEST_CASE("Exercise 00 - Add, Subtract and Scale") {

    SUBCASE("vec addition") {
        pml::vec<int, 3> v1 = {1, 2, 3};
        pml::vec<int, 3> v2 = {4, 5, 6};
        pml::vec<int, 3> expected = {5, 7, 9};

        CHECK(v1 + v2 == expected);

        v1 += v2;
        CHECK(v1 == expected);
    }

    SUBCASE("vec subtraction") {
        pml::vec<int, 3> v1 = {1, 2, 3};
        pml::vec<int, 3> v2 = {4, 5, 6};
        pml::vec<int, 3> expected = {-3, -3, -3};

        CHECK(v1 - v2 == expected);

        v1 -= v2;
        CHECK(v1 == expected);
    }

    SUBCASE("vec scalar multiplication") {
        pml::vec<int, 3> v1 = {1, 2, 3};
        int scalar = 2;
        pml::vec<int, 3> expected = {2, 4, 6};

        CHECK(v1 * scalar == expected);

        v1 *= scalar;
        CHECK(v1 == expected);
    }

    SUBCASE("mat addition") {
        pml::mat<int, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
        pml::mat<int, 2, 3> m2 = {{7, 8, 9}, {10, 11, 12}};
        pml::mat<int, 2, 3> expected = {{8, 10, 12}, {14, 16, 18}};

        CHECK(m1 + m2 == expected);

        m1 += m2;
        CHECK(m1 == expected);
    }

    SUBCASE("mat subtraction") {
        pml::mat<int, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
        pml::mat<int, 2, 3> m2 = {{7, 8, 9}, {10, 11, 12}};
        pml::mat<int, 2, 3> expected = {{-6, -6, -6}, {-6, -6, -6}};

        CHECK(m1 - m2 == expected);

        m1 -= m2;
        CHECK(m1 == expected);
    }

    SUBCASE("mat scalar multiplication") {
        pml::mat<int, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
        int scalar = 2;
        pml::mat<int, 2, 3> expected = {{2, 4, 6}, {8, 10, 12}};

        CHECK(m1 * scalar == expected);

        m1 *= scalar;
        CHECK(m1 == expected);
    }
}

TEST_CASE("Exercise 01 - Linear combination") {

    SUBCASE("vec linear combination") {
        pml::vec<int, 3> v1 = {1, 2, 3};
        pml::vec<int, 3> v2 = {4, 5, 6};
        pml::vec<int, 3> v3 = {7, 8, 9};
        pml::vec<int, 3> vectors[3] = {v1, v2, v3};

        int scalars[3] = {2, -1, 3};

        // 2*v1 - v2 + 3*v3 = (19, 23, 27)
        pml::vec<int, 3> expected = {19, 23, 27};

        pml::vec<int, 3> result = pml::linear_combination(vectors, scalars);

        CHECK(result == expected);
    }

    SUBCASE("mat linear combination") {
        pml::mat<int, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
        pml::mat<int, 2, 3> m2 = {{7, 8, 9}, {10, 11, 12}};
        pml::mat<int, 2, 3> m3 = {{13, 14, 15}, {16, 17, 18}};
        pml::mat<int, 2, 3> matrices[3] = {m1, m2, m3};

        int scalars[3] = {2, -1, 3};

        // 2*m1 - m2 + 3*m3
        pml::mat<int, 2, 3> expected = {{34, 38, 42}, {46, 50, 54}};

        pml::mat<int, 2, 3> result = pml::linear_combination(matrices, scalars);

        CHECK(result == expected);
    }
}

TEST_CASE("Exercise 02 - Linear interpolation") {

    SUBCASE("vec lerp") {
        pml::vec<float, 3> v1 = {1, 2, 3};
        pml::vec<float, 3> v2 = {4, 5, 6};
        float scalar = 0.5f;

        // v1 + (v2 - v1) * 0.5
        pml::vec<float, 3> result = pml::lerp(v1, v2, scalar);

        CHECK(result.data[0] == doctest::Approx(2.5f));
        CHECK(result.data[1] == doctest::Approx(3.5f));
        CHECK(result.data[2] == doctest::Approx(4.5f));
    }

    SUBCASE("mat lerp") {
        pml::mat<float, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
        pml::mat<float, 2, 3> m2 = {{7, 8, 9}, {10, 11, 12}};
        float scalar = 0.5f;

        pml::mat<float, 2, 3> result = pml::lerp(m1, m2, scalar);

        CHECK(result.data[0][0] == doctest::Approx(4.0f));
        CHECK(result.data[0][1] == doctest::Approx(5.0f));
        CHECK(result.data[0][2] == doctest::Approx(6.0f));
        CHECK(result.data[1][0] == doctest::Approx(7.0f));
        CHECK(result.data[1][1] == doctest::Approx(8.0f));
        CHECK(result.data[1][2] == doctest::Approx(9.0f));
    }
}

TEST_CASE("Exercise 03 - Dot product") {
    SUBCASE("vec dot product") {
        pml::vec<float, 3> v1 = {1.0f, 2.0f, 3.0f};
        pml::vec<float, 3> v2 = {4.0f, 5.0f, 6.0f};

        float result1 = v1.dot(v2);
        float result2 = pml::dot(v1, v2);

        CHECK(result1 == doctest::Approx(32.0f));
        CHECK(result2 == doctest::Approx(32.0f));
    }

    SUBCASE("mat dot product") {
        pml::mat<float, 2, 3> m1 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}};
        pml::mat<float, 2, 3> m2 = {{7.0f, 8.0f, 9.0f}, {10.0f, 11.0f, 12.0f}};

        float result = m1.dot(m2);

        CHECK(result == doctest::Approx(217.0f));
    }
}

TEST_CASE("Exercise 04 - Norm") {
    SUBCASE("vec norm") {
        pml::vec<float, 3> v1 = {1.0f, 2.0f, 3.0f};

        CHECK(v1.norm_1() == doctest::Approx(6.0f));
        CHECK(v1.norm() == doctest::Approx(3.74165738677f));
        CHECK(v1.norm_inf() == doctest::Approx(3.0f));

        CHECK(pml::norm_1(v1) == doctest::Approx(6.0f));
        CHECK(pml::norm(v1) == doctest::Approx(3.74165738677f));
        CHECK(pml::norm_inf(v1) == doctest::Approx(3.0f));
    }

    SUBCASE("mat norm") {
        pml::mat<float, 2, 3> m1 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}};

        CHECK(m1.norm_1() == doctest::Approx(21.0f));
        CHECK(m1.norm() == doctest::Approx(9.5394f));
        CHECK(m1.norm_inf() == doctest::Approx(6.0f));

        CHECK(pml::norm_1(m1) == doctest::Approx(21.0f));
        CHECK(pml::norm(m1) == doctest::Approx(9.5394f));
        CHECK(pml::norm_inf(m1) == doctest::Approx(6.0f));
    }
}