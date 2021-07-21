namespace Platform::Incrementers
{
    template<typename...> class Incrementer;
    template<> class Incrementer<>
    {
        protected: std::uint64_t _result {};

        public: [[nodiscard]] auto Result() const noexcept { return _result; }

        public: explicit Incrementer(std::uint64_t initialValue) : _result(initialValue)
        {
        }

        public: Incrementer() = default;

        public: void Increment() { _result++; }
    };
}
