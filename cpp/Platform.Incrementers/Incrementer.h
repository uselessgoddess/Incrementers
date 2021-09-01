namespace Platform::Incrementers
{
    template<typename TValue = std::size_t, typename TDecision = bool>
    class Incrementer
    {
        using base = Incrementer;
        private: const TDecision _trueValue {};

        protected: std::size_t _result {};

        public: [[nodiscard]] auto Result() const noexcept { return _result; }

        public: explicit Incrementer(TValue value = {}, TDecision trueValue = true) requires std::same_as<TDecision, bool>
            : _result(value), _trueValue(trueValue)
        {
        }

        public: explicit Incrementer(TValue value, TDecision trueValue)
            : _result(value), _trueValue(trueValue)
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
    };
}
