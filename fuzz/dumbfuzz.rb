#!/usr/bin/env ruby -wKU




fuzzfactor = ARGV[3].to_i


xFactor = (buflen.to_f / fuzzfactor).ceil
numwritesrange = (0..xFactor).to_a
numwrites = numwritesrange.choice + 1
rbyterange = (0..255).to_a
randoffsetrange = (0..(buflen-1)).to_a

numwrites.times do |i|
  rbyte = rbyterange.choice
  rchar = sprintf("%c", rbyte)
  rn = randoffsetrange.choice
  testbuf[rn] = rchar
end