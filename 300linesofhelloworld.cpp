#include <iostream>
#include <type_traits>
#include <utility>

using namespace std;

namespace a {
    namespace b {
        template <typename... T>
        struct c {
            static constexpr size_t d = sizeof...(T);
        };

        template <typename T>
        struct e;

        template <typename T, typename... U>
        struct e<c<T, U...>> {
            using f = T;
        };

        template <typename T>
        struct g;

        template <typename T, typename... U>
        struct g<c<T, U...>> {
            using f = c<U...>;
        };

        template <typename T, typename U>
        struct h;

        template <typename... T, typename U>
        struct h<c<T...>, U> {
            using f = c<T..., U>;
        };

        template <typename T, typename U>
        struct i;

        template <typename... T, typename U>
        struct i<c<T...>, U> {
            using f = c<U, T...>;
        };

        template <typename T, typename U>
        struct j;

        template <typename... T, typename... U>
        struct j<c<T...>, c<U...>> {
            using f = c<T..., U...>;
        };

        template <size_t N, typename T>
        struct k;

        template <typename T, typename... U>
        struct k<0, c<T, U...>> {
            using f = T;
        };

        template <size_t N, typename T, typename... U>
        struct k<N, c<T, U...>> {
            using f = typename k<N - 1, c<U...>>::f;
        };

        template <typename T, typename U>
        struct l;

        template <typename T>
        struct l<T, c<>> : false_type {};

        template <typename T, typename U, typename... V>
        struct l<T, c<U, V...>> : l<T, c<V...>> {};

        template <typename T, typename... U>
        struct l<T, c<T, U...>> : true_type {};

        template <typename T>
        struct m;

        template <>
        struct m<c<>> {
            using f = c<>;
        };

        template <typename T, typename... U>
        struct m<c<T, U...>> {
            using f = typename h<typename m<c<U...>>::f, T>::f;
        };
    }

    namespace n {
        template <char C>
        struct o {
            static constexpr char p = C;
            using f = o<C>;
        };

        using q = o<'H'>;
        using r = o<'e'>;
        using s = o<'l'>;
        using t = o<'o'>;
        using u = o<','>;
        using v = o<' '>;
        using w = o<'W'>;
        using x = o<'r'>;
        using y = o<'d'>;
        using z = o<'!'>;
        using aa = o<'\n'>;

        using ab = b::c<q, r, s, s, t, u, v, w, t, x, s, y, z>;
    }

    namespace ac {
        enum class ad {
            ae,
            af,
            ag,
            ah,
            ai,
            aj,
            ak,
            al,
            am
        };

        template <ad Op, int Arg = 0>
        struct an {
            static constexpr ad ao = Op;
            static constexpr int ap = Arg;
        };

        template <typename... T>
        struct aq {
            using ar = b::c<T...>;
        };

        template <typename T, size_t U = 0>
        class as {
        private:
            int at[256];
            int au;

        public:
            constexpr as() : at{0}, au(-1) {}

            void av() {
                using aw = typename T::ar;
                if constexpr (U < aw::d) {
                    using ax = typename b::k<U, aw>::f;
                    
                    if constexpr (ax::ao == ad::af) {
                        at[++au] = ax::ap;
                    } else if constexpr (ax::ao == ad::al) {
                        cout << static_cast<char>(ax::ap);
                    } else if constexpr (ax::ao == ad::am) {
                        return;
                    }
                    
                    as<T, U + 1> ay;
                    ay.az(at, au);
                }
            }

            void az(int* ba, int bb) {
                au = bb;
                for(int i = 0; i <= au; ++i) {
                    at[i] = ba[i];
                }

                using aw = typename T::ar;
                if constexpr (U < aw::d) {
                    using ax = typename b::k<U, aw>::f;
                    
                    if constexpr (ax::ao == ad::af) {
                        at[++au] = ax::ap;
                    } else if constexpr (ax::ao == ad::al) {
                        cout << static_cast<char>(ax::ap);
                    } else if constexpr (ax::ao == ad::am) {
                        return;
                    }

                    if constexpr (U + 1 < aw::d) {
                        as<T, U + 1> ay;
                        ay.az(at, au);
                    }
                }
            }
        };
    }

    namespace bc {
        class bd {
        public:
            virtual ~bd() = default;
            virtual void be() = 0;
            virtual int bf() const = 0;
        };

        template <int ID, char Char>
        class bg : public bd {
        public:
            void be() override {
                cout << Char;
            }
            int bf() const override {
                return ID;
            }
        };

        template <typename... T>
        class bh {
        private:
            bd* bi[sizeof...(T)];
            size_t bj;

        public:
            bh() : bi{nullptr}, bj(0) {
                bk<T...>(make_index_sequence<sizeof...(T)>{});
            }

            template <typename U, typename... V, size_t I, size_t... W>
            void bk(index_sequence<I, W...>) {
                bi[I] = new U();
                if constexpr (sizeof...(V) > 0) {
                    bk<V...>(index_sequence<W...>{});
                }
            }

            template <size_t I>
            void bk(index_sequence<>) {}

            void bl() {
                for (size_t i = 0; i < sizeof...(T); ++i) {
                    if (bi[i]) {
                        bi[i]->be();
                    }
                }
            }

            ~bh() {
                for (size_t i = 0; i < sizeof...(T); ++i) {
                    delete bi[i];
                }
            }
        };
    }

    namespace bm {
        template <typename T>
        class bn {
        public:
            virtual ~bn() = default;
            virtual T bo(T input) = 0;
        };

        template <typename T, typename... U>
        class bp {
        public:
            T bq(T initial) {
                return initial;
            }
        };

        template <typename T, typename U, typename... V>
        class bp<T, U, V...> {
        private:
            U br;
            bp<T, V...> bs;

        public:
            T bq(T initial) {
                T bt = br.bo(initial);
                return bs.bq(bt);
            }
        };

        class bu : public bn<char> {
        public:
            char bo(char input) override {
                return input;
            }
        };
    }
}

namespace bv {
    using namespace a;

    using bw = ac::aq<
        ac::an<ac::ad::af, 72>,
        ac::an<ac::ad::al, 72>,
        ac::an<ac::ad::af, 101>,
        ac::an<ac::ad::al, 101>,
        ac::an<ac::ad::af, 108>,
        ac::an<ac::ad::al, 108>,
        ac::an<ac::ad::af, 108>,
        ac::an<ac::ad::al, 108>,
        ac::an<ac::ad::af, 111>,
        ac::an<ac::ad::al, 111>,
        ac::an<ac::ad::af, 44>,
        ac::an<ac::ad::al, 44>,
        ac::an<ac::ad::af, 32>,
        ac::an<ac::ad::al, 32>,
        ac::an<ac::ad::af, 87>,
        ac::an<ac::ad::al, 87>,
        ac::an<ac::ad::af, 111>,
        ac::an<ac::ad::al, 111>,
        ac::an<ac::ad::af, 114>,
        ac::an<ac::ad::al, 114>,
        ac::an<ac::ad::af, 108>,
        ac::an<ac::ad::al, 108>,
        ac::an<ac::ad::af, 100>,
        ac::an<ac::ad::al, 100>,
        ac::an<ac::ad::af, 33>,
        ac::an<ac::ad::al, 33>,
        ac::an<ac::ad::am, 0>
    >;

    using bx = bc::bh<
        bc::bg<1, 'H'>,
        bc::bg<2, 'e'>,
        bc::bg<3, 'l'>,
        bc::bg<4, 'l'>,
        bc::bg<5, 'o'>,
        bc::bg<6, ','>,
        bc::bg<7, ' '>,
        bc::bg<8, 'W'>,
        bc::bg<9, 'o'>,
        bc::bg<10, 'r'>,
        bc::bg<11, 'l'>,
        bc::bg<12, 'd'>,
        bc::bg<13, '!'>
    >;
}

int main() {
    bv::bx by;
    by.bl();
    cout << endl;
    return 0;
}