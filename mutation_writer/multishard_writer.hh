/*
 * Copyright (C) 2018-present ScyllaDB
 */

/*
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#pragma once

#include "schema_fwd.hh"
#include "flat_mutation_reader.hh"
#include "dht/i_partitioner.hh"
#include "utils/phased_barrier.hh"

namespace mutation_writer {

future<uint64_t> distribute_reader_and_consume_on_shards(schema_ptr s,
    flat_mutation_reader_v2 producer,
    std::function<future<> (flat_mutation_reader_v2)> consumer,
    utils::phased_barrier::operation&& op = {});

} // namespace mutation_writer
