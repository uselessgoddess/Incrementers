namespace Platform::Incrementers
{
    template<typename...> class Incrementer;
    template<typename TValue, typename TDecision>
    class Incrementer<TValue, TDecision> : public Incrementer<>
    {
        private: using base = Incrementer<>;
        private: const TDecision _trueValue {};

        public: explicit Incrementer(std::uint64_t initialValue, TDecision trueValue) : base(initialValue), _trueValue(trueValue)
        {
        }

        public: explicit Incrementer(TDecision trueValue) : _trueValue(trueValue)
        {
        }

        public: Incrementer() = default;

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
