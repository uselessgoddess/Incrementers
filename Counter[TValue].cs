using System.Runtime.CompilerServices;

#pragma warning disable IDE0060 // Remove unused parameter
#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Counters
{
    public class Counter<TValue> : Counter
    {
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public bool IncrementAndReturnTrue()
        {
            _count++;
            return true;
        }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public bool IncrementAndReturnTrue(TValue value)
        {
            _count++;
            return true;
        }
    }
}
