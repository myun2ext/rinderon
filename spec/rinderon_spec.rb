require "rinderon"

describe Rinderon do
  it { expect(Rinderon::Window.new.hello).to eq "hello" }
end
