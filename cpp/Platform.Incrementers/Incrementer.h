namespace Platform::Incrementers
{
    template<typename...> class Incrementer;
    template<> class Incrementer<>
    {
        protected: std::size_t _result {};

        public: [[nodiscard]] auto Result() const noexcept { return _result; }

        public: explicit Incrementer(std::uint64_t initialValue) : _result(initialValue)
        {
        }

        public: Incrementer() = default;

        public: void Increment() noexcept { _result++; }
    };
}
