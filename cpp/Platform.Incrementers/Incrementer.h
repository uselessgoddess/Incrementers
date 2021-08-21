namespace Platform::Incrementers::Internal
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

        public: explicit Incrementer(TValue value = {}, TDecision trueValue = Internal::true_or_default<TDecision>())
            : _result(value), _trueValue(trueValue)
        {
        }

        public: void Increment() noexcept { _result++; }

        public: TDecision IncrementAndReturnTrue()
        {
            Increment();
            return _trueValue;
        }

        public: TDecision IncrementAndReturnTrue(TValue value)
        {
            Increment();
            return _trueValue;
        }
    };
}
