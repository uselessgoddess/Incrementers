using System.Runtime.CompilerServices;

#pragma warning disable CS1591 // Missing XML comment for publicly visible type or member

namespace Platform.Incrementers
{
    /// <remarks>
    /// Must be class, not struct (in order to persist access to Result field value).
    /// </remarks>
    public class Incrementer : IIncrementer
    {
        protected ulong _result;

        public ulong Result => _result;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer(ulong initialValue) => _result = initialValue;

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public Incrementer() { }

        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public void Increment() => _result++;
    }
}
