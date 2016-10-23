#ifndef CONTROLLER_HH
#define CONTROLLER_HH

#include <cstdint>
#include <deque>

using namespace std;

/* Congestion controller interface */

class Controller
{
private:
    bool debug_;

    // Additive increase
    int ai = 5;

    // Multiplicative decrease
    double md = 0.5;

    // Current window size
    int cur_ws = 1;

    uint64_t delay_thresh = 50;

    uint64_t desired_rtt = 70;
    uint64_t last_ts = 0;
    double Kp = 0.01, Ki = 0.1, Kd = 0.05;
    double link_rate = 0.0;
    int counter = 0;
    uint64_t start_time = 0;

public:
    Controller(const bool debug);

    unsigned int window_size();

    void datagram_was_sent(const uint64_t sequence_number,
                const uint64_t send_timestamp);

    void ack_received(const uint64_t sequence_number_acked,
                const uint64_t send_timestamp_acked,
                const uint64_t recv_timestamp_acked,
                const uint64_t timestamp_ack_received);

    unsigned int timeout_ms();
};

#endif
