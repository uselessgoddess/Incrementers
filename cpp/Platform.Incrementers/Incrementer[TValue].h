namespace Platform::Incrementers
{
    template<typename...> class Incrementer;
    template<typename TValue> class Incrementer<TValue> : public Incrementer<TValue, bool>
    {
        private: using base = Incrementer<TValue, bool>;

        public: explicit Incrementer(std::uint64_t initialValue) : base(initialValue, true)
        {
        }

        public: Incrementer() : base(true)
        {
        }
    };
}
