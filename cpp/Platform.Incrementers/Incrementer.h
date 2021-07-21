namespace Internal
{
    template<typename decision_type>
    constexpr auto true_or_default()
    {
        if constexpr (std::integral<decision_type>)
        {
            return decision_type{1};
        }
        else
        {
            return decision_type{};
        }
    }
}

namespace Platform::Incrementers
{
    template<typename TValue = std::size_t, typename TDecision = bool>
    class Incrementer
    {
        using base = Incrementer;
        private: const TDecision _trueValue {};

        protected: std::size_t _result {};

        public: [[nodiscard]] auto Result() const noexcept { return _result; }

        public: Incrementer() = default;

        public: explicit Incrementer(TValue value = {}, TDecision decision = Internal::true_or_default<TDecision>()): _trueValue(trueValue)
        {
        }

        public: void Increment() noexcept { _result++; }

        public: TDecision IncrementAndReturnTrue()
        {
            _result++;
            return _trueValue;
        }

        public: TDecision IncrementAndReturnTrue(TValue value)
        {
            _result++;
            return _trueValue;
        }

        /*using anotherbase = Incrementer<TValue, bool>;

        public: explicit Incrementer(std::size_t initialValue) : anotherbase(initialValue, true)
        {
        }

        public: Incrementer() : anotherbase(true)
        {
        }*/
    };
}
