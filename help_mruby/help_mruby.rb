module Groonga
  module HelpMruby
    class HelpCommand < Command
      register("help_mruby", [])

      def run_body(input)
        writer.write("hi")
      end
    end
  end
end
