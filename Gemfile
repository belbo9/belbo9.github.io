# frozen_string_literal: true

source "https://rubygems.org"

gem 'wdm', '~> 0.1', :install_if => Gem.win_platform?

gem 'webrick'

platforms :mingw, :x64_mingw, :mswin, :jruby do
  gem 'tzinfo', '>= 1', '< 3'
  gem 'tzinfo-data'
end

group :jekyll_plugins do
  gem 'github-pages'
  gem 'jekyll-octicons'
  gem 'jekyll-feed'
  gem 'jekyll-sitemap'
  gem 'jekyll-redirect-from'
  gem 'jemoji'
  gem 'jekyll'
  gem 'connection_pool', '2.5.0'
  gem 'breakpoint'
end

