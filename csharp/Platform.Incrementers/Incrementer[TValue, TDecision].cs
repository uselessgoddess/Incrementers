using System.Runtime.CompilerServices;

#pragma warning disable IDE0060 // Remove unused parameter
#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Incrementers
{
    public class Incrementer<TValue, TDecision> : Incrementer
    {
        private readonly TDecision _trueValue;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer(ulong initialValue, TDecision trueValue) : base(initialValue) => _trueValue = trueValue;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer(TDecision trueValue) => _trueValue = trueValue;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer() { }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public TDecision IncrementAndReturnTrue()
        {
            _result++;
            return _trueValue;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public TDecision IncrementAndReturnTrue(TValue value)
        {
            _result++;
            return _trueValue;
        }
    }
}
