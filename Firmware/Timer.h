/**
 * @file
 * @author Marek Bel
 */

#ifndef TIMER_H
#define TIMER_H

/**
 * @brief simple timer
 *
 * Simple and memory saving implementation. Should handle timer register wrap around well.
 * Resolution is one millisecond. To save memory, doesn't store timer period.
 * If you wish timer which is storing period, derive from this.
 */
template <class T>
class Timer
{
public:
    Timer();
    void start();
    void stop(){m_isRunning = false;}
    bool running()const {return m_isRunning;}
    bool expired(T msPeriod);
    T elapsed();
protected:
    T started()const {return m_started;}
private:
    bool m_isRunning;
    T m_started;
};

/**
 * @brief Timer unsigned long specialization
 *
 * Maximum period is at least 49 days.
 */
#if __cplusplus>=201103L
using LongTimer = Timer<unsigned long>;
#else
typedef Timer<unsigned long> LongTimer;
#endif
/**
 * @brief Timer unsigned short specialization
 *
 * Maximum period is at least 65 seconds.
 */
#if __cplusplus>=201103L
using ShortTimer = Timer<unsigned short>;
#else
typedef Timer<unsigned short> ShortTimer;
#endif

#endif /* TIMER_H */
