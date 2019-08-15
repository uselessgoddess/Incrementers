using System.Runtime.CompilerServices;

#pragma warning disable IDE0060 // Remove unused parameter
#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Counters
{
    public class Counter<TValue, TDecision> : Counter
    {
        private readonly TDecision _trueValue;

        public Counter(TDecision trueValue) => _trueValue = trueValue;

        public Counter() { }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public TDecision IncrementAndReturnTrue()
        {
            _count++;
            return _trueValue;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public TDecision IncrementAndReturnTrue(TValue value)
        {
            _count++;
            return _trueValue;
        }
    }
}
