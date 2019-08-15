using System.Runtime.CompilerServices;

#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Counters
{
    /// <remarks>
    /// Must be class, not struct (in order to persist access to Count field value).
    /// </remarks>
    public class Counter
    {
        protected ulong _count;
        public ulong Count => _count;
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public void Increment() => _count++;
    }
}
