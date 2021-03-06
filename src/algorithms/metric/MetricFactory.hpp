#pragma once

namespace DataMining
{
	namespace Metrics
	{
		class MetricFactory
		{
		public:
			template<typename ... Args>
			static DistanceMetric * GetMetric(MetricTypes type, Args... args)
			{
				DistanceMetric * result;
				switch (type)
				{
					case MetricTypes::DTW: result = new DynamicTimeWarping(); break;
					case MetricTypes::Minkowski: result = new MinkowskiMetric(args...); break;
					case MetricTypes::Chebyshev: result = new ChebyshevMetric(); break;
					default:  result = new MinkowskiMetric(args...); break;
				}
				return result;
			}
		};
	}
}
