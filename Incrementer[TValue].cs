using System.Runtime.CompilerServices;

#pragma warning disable IDE0060 // Remove unused parameter
#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Incrementers
{
    public class Incrementer<TValue> : Incrementer<TValue, bool>
    {
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer(ulong initialValue) : base(initialValue, true) { }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer() { }
    }
}
